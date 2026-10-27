/-
  Formalization of:
  "Making the Linux eBPF Verifier Sound and Using it for Profit with Abstract Step Functions"
  (pldi.pdf / pldi_revised.tex)

  All definitions, algorithms, and theorems in this file are **parametric in bitwidth**:
  - Single-width abstract domains, step functions (`tnum_step`), One-Step Interval
    Intersection (Theorem 4.2), and Multi-Domain Set Intersection (Algorithm 2 & Theorem 5.1)
    are parameterized over an arbitrary bitwidth `w : Nat`.
  - Full-register + subregister product domains (`RegState w_lo w_hi`), the state-space
    partition (`WF`, `CM`, `EI`, `IF_state`), the Dead Branch Principle (Theorem 3.1),
    and the 3-stage `reg_bounds_intersect` pipeline (§6) are parameterized over arbitrary
    subregister width `w_lo : Nat` and upper-prefix width `w_hi : Nat` (giving full register
    width `w_lo + w_hi`, instantiated to `w_lo = 32, w_hi = 32` for 64-bit eBPF examples).
-/

namespace PLDIProofs

/-!
================================================================================
## §1. Parametric BitVector & Subregister Slicing Foundations
================================================================================
We first establish bitwidth-parametric lemmas for `BitVec w` (by `BitVec.cons`
decomposition on `w : Nat`) and for splitting a `(w_lo + w_hi)`-bit register
into its `w_lo`-bit lower subregister (`loSlice`) and `w_hi`-bit upper prefix (`hiSlice`).
-/

theorem cons_inj {w : Nat} {a b : Bool} {x y : BitVec w} :
    BitVec.cons a x = BitVec.cons b y ↔ a = b ∧ x = y := by
  constructor
  · intro h
    have h1 := congrArg BitVec.msb h
    have h2 := congrArg (BitVec.setWidth w) h
    rw [BitVec.msb_cons, BitVec.msb_cons] at h1
    rw [BitVec.setWidth_cons, BitVec.setWidth_cons] at h2
    exact ⟨h1, h2⟩
  · rintro ⟨rfl, rfl⟩
    rfl

theorem cons_zero {n : Nat} : BitVec.cons false (0#n) = 0#(n + 1) := by
  have h := BitVec.cons_msb_setWidth (0#(n + 1))
  rw [BitVec.msb_zero, BitVec.setWidth_zero] at h
  exact h

theorem cons_and {w : Nat} (a b : Bool) (x y : BitVec w) :
    BitVec.cons a x &&& BitVec.cons b y = BitVec.cons (a && b) (x &&& y) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_and, BitVec.getLsbD_cons]
  split <;> rfl

theorem cons_or {w : Nat} (a b : Bool) (x y : BitVec w) :
    BitVec.cons a x ||| BitVec.cons b y = BitVec.cons (a || b) (x ||| y) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [BitVec.getLsbD_or, BitVec.getLsbD_cons]
  split <;> rfl

theorem toNat_cons_eq {w : Nat} (a : Bool) (x : BitVec w) :
    (BitVec.cons a x).toNat = a.toNat * 2 ^ w + x.toNat := by
  rw [BitVec.toNat_cons', Nat.shiftLeft_eq]

theorem cons_lt_cons_iff {w : Nat} (b1 b2 : Bool) (x1 x2 : BitVec w) :
    BitVec.cons b1 x1 < BitVec.cons b2 x2 ↔
      (b1 = false ∧ b2 = true) ∨ (b1 = b2 ∧ x1 < x2) := by
  rw [BitVec.lt_def, BitVec.lt_def, toNat_cons_eq, toNat_cons_eq]
  have hx1 : x1.toNat < 2 ^ w := x1.isLt
  have hx2 : x2.toNat < 2 ^ w := x2.isLt
  cases b1 <;> cases b2 <;> simp <;> omega

theorem cons_le_cons_iff {w : Nat} (b1 b2 : Bool) (x1 x2 : BitVec w) :
    BitVec.cons b1 x1 ≤ BitVec.cons b2 x2 ↔
      (b1 = false ∧ b2 = true) ∨ (b1 = b2 ∧ x1 ≤ x2) := by
  rw [BitVec.le_def, BitVec.le_def, toNat_cons_eq, toNat_cons_eq]
  have hx1 : x1.toNat < 2 ^ w := x1.isLt
  have hx2 : x2.toNat < 2 ^ w := x2.isLt
  cases b1 <;> cases b2 <;> simp <;> omega

theorem lt_succ_iff {w : Nat} (x y : BitVec (w + 1)) :
    x < y ↔ (x.msb = false ∧ y.msb = true) ∨ (x.msb = y.msb ∧ x.setWidth w < y.setWidth w) := by
  conv => lhs; rw [← BitVec.cons_msb_setWidth x, ← BitVec.cons_msb_setWidth y]
  exact cons_lt_cons_iff x.msb y.msb (x.setWidth w) (y.setWidth w)

theorem le_succ_iff {w : Nat} (x y : BitVec (w + 1)) :
    x ≤ y ↔ (x.msb = false ∧ y.msb = true) ∨ (x.msb = y.msb ∧ x.setWidth w ≤ y.setWidth w) := by
  conv => lhs; rw [← BitVec.cons_msb_setWidth x, ← BitVec.cons_msb_setWidth y]
  exact cons_le_cons_iff x.msb y.msb (x.setWidth w) (y.setWidth w)

theorem msb_or {w : Nat} (x y : BitVec (w + 1)) :
    (x ||| y).msb = (x.msb || y.msb) := by
  conv => lhs; rw [← BitVec.cons_msb_setWidth x, ← BitVec.cons_msb_setWidth y, cons_or, BitVec.msb_cons]

theorem setWidth_or {w : Nat} (x y : BitVec (w + 1)) :
    (x ||| y).setWidth w = (x.setWidth w ||| y.setWidth w) := by
  conv => lhs; rw [← BitVec.cons_msb_setWidth x, ← BitVec.cons_msb_setWidth y, cons_or, BitVec.setWidth_cons]

theorem le_allOnes {w : Nat} (x : BitVec w) : x ≤ BitVec.allOnes w := by
  rw [BitVec.le_def, BitVec.toNat_allOnes]
  have := x.isLt
  omega

theorem zero_le_bv {w : Nat} (x : BitVec w) : 0#w ≤ x := by
  rw [BitVec.le_def]
  simp

/-- Lower `w_lo`-bit subregister slice `x[w_lo - 1 : 0]` of a `(w_lo + w_hi)`-bit word. -/
def loSlice {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) : BitVec w_lo :=
  x.extractLsb' 0 w_lo

/-- Upper `w_hi`-bit prefix slice `x[w_lo + w_hi - 1 : w_lo]` of a `(w_lo + w_hi)`-bit word. -/
def hiSlice {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) : BitVec w_hi :=
  x.extractLsb' w_lo w_hi

/-- Reconstruct a `(w_lo + w_hi)`-bit word from its upper prefix `k` and lower subregister `lo`. -/
def mkWord {w_lo w_hi : Nat} (k : BitVec w_hi) (lo : BitVec w_lo) : BitVec (w_lo + w_hi) :=
  (k.setWidth (w_lo + w_hi) <<< w_lo) ||| lo.setWidth (w_lo + w_hi)

theorem mkWord_hi_lo {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    mkWord (hiSlice x) (loSlice x) = x := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp only [mkWord, hiSlice, loSlice, BitVec.getLsbD_or, BitVec.getLsbD_shiftLeft,
    BitVec.getLsbD_setWidth, BitVec.getLsbD_extractLsb', Nat.zero_add]
  by_cases h : i < w_lo
  · simp [h, hi]
  · have h1 : i - w_lo < w_hi := by omega
    have h2 : w_lo + (i - w_lo) = i := by omega
    have h3 : i - w_lo < w_lo + w_hi := by omega
    simp [h, hi, h1, h2, h3]

theorem hiSlice_mkWord {w_lo w_hi : Nat} (k : BitVec w_hi) (lo : BitVec w_lo) :
    hiSlice (mkWord k lo) = k := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  have h1 : w_lo + i < w_lo + w_hi := by omega
  have h2 : ¬(w_lo + i < w_lo) := by omega
  have h3 : (w_lo + i) - w_lo = i := by omega
  simp [hiSlice, mkWord, hi, h1, h2, h3]

theorem loSlice_mkWord {w_lo w_hi : Nat} (k : BitVec w_hi) (lo : BitVec w_lo) :
    loSlice (mkWord k lo) = lo := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  have h1 : i < w_lo + w_hi := by omega
  simp [loSlice, mkWord, hi, h1]

theorem word_ext_slices {w_lo w_hi : Nat} {x y : BitVec (w_lo + w_hi)} :
    x = y ↔ hiSlice x = hiSlice y ∧ loSlice x = loSlice y := by
  constructor
  · rintro rfl; exact ⟨rfl, rfl⟩
  · rintro ⟨hhi, hlo⟩
    rw [← mkWord_hi_lo x, ← mkWord_hi_lo y, hhi, hlo]

theorem loSlice_and {w_lo w_hi : Nat} (x y : BitVec (w_lo + w_hi)) :
    loSlice (x &&& y) = loSlice x &&& loSlice y := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp [loSlice, hi]

theorem hiSlice_and {w_lo w_hi : Nat} (x y : BitVec (w_lo + w_hi)) :
    hiSlice (x &&& y) = hiSlice x &&& hiSlice y := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp [hiSlice, hi]

theorem loSlice_not {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    loSlice (~~~x) = ~~~(loSlice x) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  have h1 : i < w_lo + w_hi := by omega
  simp [loSlice, hi, h1]

theorem hiSlice_not {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    hiSlice (~~~x) = ~~~(hiSlice x) := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  have h1 : w_lo + i < w_lo + w_hi := by omega
  simp [hiSlice, hi, h1]

theorem loSlice_zero {w_lo w_hi : Nat} :
    loSlice (0#(w_lo + w_hi)) = 0#w_lo := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp [loSlice]

theorem hiSlice_zero {w_lo w_hi : Nat} :
    hiSlice (0#(w_lo + w_hi)) = 0#w_hi := by
  apply BitVec.eq_of_getLsbD_eq
  intro i hi
  simp [hiSlice]

theorem toNat_loSlice {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    (loSlice x).toNat = x.toNat % 2 ^ w_lo := by
  simp [loSlice, BitVec.extractLsb'_toNat]

theorem toNat_hiSlice {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    (hiSlice x).toNat = x.toNat / 2 ^ w_lo := by
  simp only [hiSlice, BitVec.extractLsb'_toNat, Nat.shiftRight_eq_div_pow]
  have hx := x.isLt
  rw [Nat.pow_add] at hx
  have hdiv : x.toNat / 2 ^ w_lo < 2 ^ w_hi := Nat.div_lt_of_lt_mul hx
  exact Nat.mod_eq_of_lt hdiv

/-- Equation (21): Every `(w_lo + w_hi)`-bit word decomposes into `k * 2^w_lo + lo`. -/
theorem word_periodicity_decomp {w_lo w_hi : Nat} (x : BitVec (w_lo + w_hi)) :
    x.toNat = (hiSlice x).toNat * 2 ^ w_lo + (loSlice x).toNat := by
  rw [toNat_hiSlice, toNat_loSlice, Nat.mul_comm]
  exact (Nat.div_add_mod x.toNat (2 ^ w_lo)).symm

theorem toNat_mkWord {w_lo w_hi : Nat} (k : BitVec w_hi) (lo : BitVec w_lo) :
    (mkWord k lo).toNat = k.toNat * 2 ^ w_lo + lo.toNat := by
  have h := word_periodicity_decomp (mkWord k lo)
  rw [hiSlice_mkWord, loSlice_mkWord] at h
  exact h

private theorem div_mod_le_iff {a b n : Nat} (hn : 0 < n) :
    a ≤ b ↔ a / n < b / n ∨ (a / n = b / n ∧ a % n ≤ b % n) := by
  have ha := (Nat.div_add_mod a n).symm
  have hb := (Nat.div_add_mod b n).symm
  have hma : a % n < n := Nat.mod_lt a hn
  have hmb : b % n < n := Nat.mod_lt b hn
  constructor
  · intro h
    by_cases hdiv : a / n < b / n
    · exact Or.inl hdiv
    · right
      have hge : b / n ≤ a / n := Nat.le_of_not_lt hdiv
      have heq : a / n = b / n := by
        apply Classical.byContradiction
        intro hne
        have hgt : b / n + 1 ≤ a / n := by omega
        have hmul : n * (b / n + 1) ≤ n * (a / n) := Nat.mul_le_mul_left n hgt
        rw [Nat.mul_add, Nat.mul_one] at hmul
        omega
      refine ⟨heq, ?_⟩
      rw [heq] at ha
      omega
  · rintro (hdiv | ⟨heq, hmod⟩)
    · have h1 : a / n + 1 ≤ b / n := hdiv
      have hmul : n * (a / n + 1) ≤ n * (b / n) := Nat.mul_le_mul_left n h1
      rw [Nat.mul_add, Nat.mul_one] at hmul
      omega
    · rw [heq] at ha
      omega

/-- Lexicographic order characterization of `(w_lo + w_hi)`-bit unsigned comparison. -/
theorem word_le_iff {w_lo w_hi : Nat} (x y : BitVec (w_lo + w_hi)) :
    x ≤ y ↔ hiSlice x < hiSlice y ∨ (hiSlice x = hiSlice y ∧ loSlice x ≤ loSlice y) := by
  rw [BitVec.le_def, BitVec.lt_def, BitVec.le_def,
      ← BitVec.toNat_inj, toNat_hiSlice, toNat_hiSlice, toNat_loSlice, toNat_loSlice]
  exact div_mod_le_iff (Nat.two_pow_pos w_lo)

/-!
================================================================================
## §2. Background: Parametric eBPF Abstract Domains & Verification Architecture
================================================================================
We formalize the five scalar abstract domains of the Linux eBPF verifier
(Equations 1–5), their product register state `RegState w_lo w_hi` (Equations 6–7),
and domain reduction operators `IsReductionOp` (Equation 8), all parametric in
bitwidth.
-/

/-- `w`-bit Unsigned Interval `[min, max]_u` (§2.1, Equation 1). -/
structure UInterval (w : Nat) where
  min : BitVec w
  max : BitVec w
  deriving DecidableEq, Repr

/-- `w`-bit Signed Interval `[smin, smax]_s` (§2.1, Equation 2). -/
structure SInterval (w : Nat) where
  smin : BitVec w
  smax : BitVec w
  deriving DecidableEq, Repr

/-- `w`-bit Tristate Number `(v, m)` (§2.1, Equation 5). -/
structure Tnum (w : Nat) where
  v : BitVec w
  m : BitVec w
  deriving DecidableEq, Repr

/-- Well-formedness of an unsigned interval: `min ≤_u max`. -/
def UInterval.wf {w : Nat} (I : UInterval w) : Prop :=
  I.min ≤ I.max

/-- Well-formedness of a signed interval: `smin ≤_s smax`. -/
def SInterval.wf {w : Nat} (I : SInterval w) : Prop :=
  I.smin.sle I.smax = true

/-- Well-formedness of a tnum: `v & m = 0` (no bit is simultaneously known-1 and unknown). -/
def Tnum.wf {w : Nat} (t : Tnum w) : Prop :=
  (t.v &&& t.m) = 0#w

instance {w : Nat} (I : UInterval w) : Decidable I.wf := by
  unfold UInterval.wf; infer_instance

instance {w : Nat} (I : SInterval w) : Decidable I.wf := by
  unfold SInterval.wf; infer_instance

instance {w : Nat} (t : Tnum w) : Decidable t.wf := by
  unfold Tnum.wf; infer_instance

/-- Equation (1): Concretization `γ_{[u_w]}([umin, umax])`. -/
def gammaU {w : Nat} (I : UInterval w) (x : BitVec w) : Prop :=
  I.min ≤ x ∧ x ≤ I.max

/-- Equation (2): Concretization `γ_{[s_w]}([smin, smax])`. -/
def gammaS {w : Nat} (I : SInterval w) (x : BitVec w) : Prop :=
  I.smin.sle x = true ∧ x.sle I.smax = true

/-- Equation (3): Full-register concretization of lower `w_lo`-bit unsigned bounds. -/
def gammaUSub {w_lo w_hi : Nat} (I : UInterval w_lo) (x : BitVec (w_lo + w_hi)) : Prop :=
  gammaU I (loSlice x)

/-- Equation (4): Full-register concretization of lower `w_lo`-bit signed bounds. -/
def gammaSSub {w_lo w_hi : Nat} (I : SInterval w_lo) (x : BitVec (w_lo + w_hi)) : Prop :=
  gammaS I (loSlice x)

/-- Equation (5): Concretization `γ_tnum(v, m) = { x ∈ W_w | (x & ~m) = v }`. -/
def gammaTnum {w : Nat} (t : Tnum w) (x : BitVec w) : Prop :=
  (x &&& ~~~t.m) = t.v

instance {w : Nat} (I : UInterval w) (x : BitVec w) : Decidable (gammaU I x) := by
  unfold gammaU; infer_instance

instance {w : Nat} (I : SInterval w) (x : BitVec w) : Decidable (gammaS I x) := by
  unfold gammaS; infer_instance

instance {w : Nat} (t : Tnum w) (x : BitVec w) : Decidable (gammaTnum t x) := by
  unfold gammaTnum; infer_instance

instance {w_lo w_hi : Nat} (I : UInterval w_lo) (x : BitVec (w_lo + w_hi)) :
    Decidable (gammaUSub I x) := by
  unfold gammaUSub; infer_instance

instance {w_lo w_hi : Nat} (I : SInterval w_lo) (x : BitVec (w_lo + w_hi)) :
    Decidable (gammaSSub I x) := by
  unfold gammaSSub; infer_instance

/-- Equation (6): Product abstract register state `R ∈ P(w_lo, w_hi)`. -/
structure RegState (w_lo w_hi : Nat) where
  u64  : UInterval (w_lo + w_hi)
  s64  : SInterval (w_lo + w_hi)
  u32  : UInterval w_lo
  s32  : SInterval w_lo
  tnum : Tnum (w_lo + w_hi)
  deriving DecidableEq, Repr

/-- Equation (7): Joint concretization `γ_P(R)` (intersection of all five domains). -/
def gammaReg {w_lo w_hi : Nat} (r : RegState w_lo w_hi) (x : BitVec (w_lo + w_hi)) : Prop :=
  gammaU r.u64 x ∧
  gammaS r.s64 x ∧
  gammaUSub r.u32 x ∧
  gammaSSub r.s32 x ∧
  gammaTnum r.tnum x

instance {w_lo w_hi : Nat} (r : RegState w_lo w_hi) (x : BitVec (w_lo + w_hi)) :
    Decidable (gammaReg r x) := by
  unfold gammaReg; infer_instance

/-- Componentwise precision preorder `R' ⊑ R` on abstract register states (§2.2). -/
def sqsubseteqReg {w_lo w_hi : Nat} (r' r : RegState w_lo w_hi) : Prop :=
  (r.u64.min ≤ r'.u64.min ∧ r'.u64.max ≤ r.u64.max) ∧
  (r.s64.smin.sle r'.s64.smin = true ∧ r'.s64.smax.sle r.s64.smax = true) ∧
  (r.u32.min ≤ r'.u32.min ∧ r'.u32.max ≤ r.u32.max) ∧
  (r.s32.smin.sle r'.s32.smin = true ∧ r'.s32.smax.sle r.s32.smax = true) ∧
  ((r'.tnum.m &&& ~~~r.tnum.m) = 0#(w_lo + w_hi) ∧
   (r'.tnum.v &&& ~~~r.tnum.m) = r.tnum.v)

/-- Equation (8): Soundness and precision specification of a domain reduction operator `ρ`. -/
structure IsReductionOp {w_lo w_hi : Nat} (rho : RegState w_lo w_hi → RegState w_lo w_hi) : Prop where
  preserves_gamma : ∀ (r : RegState w_lo w_hi) (x : BitVec (w_lo + w_hi)),
    gammaReg r x → gammaReg (rho r) x
  tightens_bounds : ∀ (r : RegState w_lo w_hi),
    (∀ x, ¬gammaReg r x) ∨ sqsubseteqReg (rho r) r

/-! ### Fundamental Parametric Tnum Lemmas -/

theorem tnum_wf_succ_iff {w : Nat} (t : Tnum (w + 1)) :
    t.wf ↔ (t.v.msb && t.m.msb) = false ∧ (Tnum.mk (t.v.setWidth w) (t.m.setWidth w)).wf := by
  unfold Tnum.wf
  dsimp
  conv => lhs; rw [← BitVec.cons_msb_setWidth t.v, ← BitVec.cons_msb_setWidth t.m, cons_and, ← cons_zero]
  exact cons_inj

theorem gammaTnum_succ_iff {w : Nat} (t : Tnum (w + 1)) (x : BitVec (w + 1)) :
    gammaTnum t x ↔
      (x.msb && !t.m.msb) = t.v.msb ∧ gammaTnum ⟨t.v.setWidth w, t.m.setWidth w⟩ (x.setWidth w) := by
  unfold gammaTnum
  dsimp
  conv => lhs; rw [← BitVec.cons_msb_setWidth x, ← BitVec.cons_msb_setWidth t.m,
                   ← BitVec.cons_msb_setWidth t.v, BitVec.not_cons, cons_and]
  exact cons_inj

theorem gammaTnum_cons_iff {w : Nat} (t : Tnum (w + 1)) (bx : Bool) (x_lo : BitVec w) :
    gammaTnum t (BitVec.cons bx x_lo) ↔
      (bx && !t.m.msb) = t.v.msb ∧ gammaTnum ⟨t.v.setWidth w, t.m.setWidth w⟩ x_lo := by
  rw [gammaTnum_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons]

/-- Every well-formed tnum contains its base value `t.v` (`t.v ∈ γ_tnum(t)`). -/
theorem self_mem_gammaTnum {w : Nat} (t : Tnum w) (hwf : t.wf) :
    gammaTnum t t.v := by
  induction w with
  | zero =>
    unfold gammaTnum
    exact Subsingleton.elim _ _
  | succ w' ih =>
    rw [tnum_wf_succ_iff] at hwf
    rw [gammaTnum_succ_iff]
    refine ⟨?_, ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ hwf.2⟩
    have h1 := hwf.1
    revert h1
    cases t.v.msb <;> cases t.m.msb <;> decide

/-- Conversely, if `γ_tnum(t)` is non-empty, then `t` is well-formed (`t.v & t.m = 0`). -/
theorem gammaTnum_implies_wf {w : Nat} (t : Tnum w) (x : BitVec w) (hx : gammaTnum t x) :
    t.wf := by
  induction w with
  | zero =>
    unfold Tnum.wf
    exact Subsingleton.elim _ _
  | succ w' ih =>
    rw [gammaTnum_succ_iff] at hx
    rw [tnum_wf_succ_iff]
    refine ⟨?_, ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ (x.setWidth w') hx.2⟩
    have h1 := hx.1
    revert h1
    cases x.msb <;> cases t.v.msb <;> cases t.m.msb <;> decide

/-- Lower bound of a tnum: every `x ∈ γ_tnum(t)` satisfies `t.v ≤_u x`. -/
theorem gammaTnum_ge_v {w : Nat} (t : Tnum w) (x : BitVec w) (hx : gammaTnum t x) :
    t.v ≤ x := by
  induction w with
  | zero =>
    rw [BitVec.le_def]
    omega
  | succ w' ih =>
    rw [gammaTnum_succ_iff] at hx
    rw [le_succ_iff]
    have hlo := ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ (x.setWidth w') hx.2
    have h1 := hx.1
    revert h1 hlo
    cases t.v.msb <;> cases t.m.msb <;> cases x.msb <;> simp

/-- Upper bound of a tnum: every `x ∈ γ_tnum(t)` satisfies `x ≤_u (t.v | t.m)`. -/
theorem gammaTnum_le_max {w : Nat} (t : Tnum w) (x : BitVec w) (hx : gammaTnum t x) :
    x ≤ (t.v ||| t.m) := by
  induction w with
  | zero =>
    rw [BitVec.le_def]
    omega
  | succ w' ih =>
    rw [gammaTnum_succ_iff] at hx
    rw [le_succ_iff, msb_or, setWidth_or]
    have hlo := ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ (x.setWidth w') hx.2
    have h1 := hx.1
    revert h1 hlo
    cases t.v.msb <;> cases t.m.msb <;> cases x.msb <;> simp

/-!
================================================================================
## §3. Unsoundness on Infeasible Paths & The Dead Branch Principle
================================================================================
We formalize Agni's conditional jump soundness criterion (Equations 9–10),
the partition of the syntactic state universe `U` into `WF`, `CM`, `EI`, and `IF`
(Equations 11–15), the motivating invariant-violation transition chain (§1 / §3.1),
and the **Dead Branch Principle (Theorem 3.1, Equation 16)**, parametric in `w_lo, w_hi`.
-/

/-- Equation (9): Agni's conditional jump refinement soundness specification `f^♯_op`. -/
def JumpRefineSound {w_lo w_hi : Nat}
    (cond : BitVec (w_lo + w_hi) → BitVec (w_lo + w_hi) → Prop)
    (refineTrue refineFalse :
      RegState w_lo w_hi → RegState w_lo w_hi → RegState w_lo w_hi × RegState w_lo w_hi) : Prop :=
  ∀ (r1 r2 : RegState w_lo w_hi) (x y : BitVec (w_lo + w_hi)),
    gammaReg r1 x → gammaReg r2 y →
      (cond x y →
        gammaReg (refineTrue r1 r2).1 x ∧ gammaReg (refineTrue r1 r2).2 y) ∧
      (¬cond x y →
        gammaReg (refineFalse r1 r2).1 x ∧ gammaReg (refineFalse r1 r2).2 y)

/-- Equation (10): When a branch condition `cond` is infeasible (`∀ x y ∈ γ_P, ¬cond x y`),
    the implication `cond x y → ...` holds **vacuously** for ANY output state `(r1_t, r2_t)`. -/
theorem jumpRefineSound_vacuous_on_infeasible_edge {w_lo w_hi : Nat}
    (cond : BitVec (w_lo + w_hi) → BitVec (w_lo + w_hi) → Prop)
    (r1 r2 r1_t r2_t : RegState w_lo w_hi)
    (h_infeasible : ∀ x y, gammaReg r1 x → gammaReg r2 y → ¬cond x y) :
    ∀ x y, gammaReg r1 x → gammaReg r2 y →
      (cond x y → gammaReg r1_t x ∧ gammaReg r2_t y) := by
  intro x y hx hy hcond
  exact absurd hcond (h_infeasible x y hx hy)

/-- Equation (12): Well-Formed States (`WF`) — each individual domain satisfies its
    local structural invariant (`umin ≤ umax`, `smin ≤ sMax`, `v & m = 0`). -/
def WF {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Prop :=
  r.u64.wf ∧ r.s64.wf ∧ r.u32.wf ∧ r.s32.wf ∧ r.tnum.wf

instance {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Decidable (WF r) := by
  unfold WF; infer_instance

/-- Equation (13): Cohesive-Measured States (`CM`) — well-formed states whose five
    domains share at least one common concrete value (`γ_P(R) ≠ ∅`). -/
def CM {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Prop :=
  WF r ∧ ∃ x : BitVec (w_lo + w_hi), gammaReg r x

/-- Equation (14): Empty-Intersection States (`EI`) — well-formed states whose five
    domains are individually valid but mutually contradictory (`γ_P(R) = ∅`). -/
def EI {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Prop :=
  WF r ∧ ∀ x : BitVec (w_lo + w_hi), ¬gammaReg r x

/-- Equation (15): Ill-Formed States (`IF`) — states violating at least one domain's
    internal ordering or mask invariant (`R ∉ WF`). -/
def IF_state {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Prop :=
  ¬WF r

instance {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Decidable (IF_state r) := by
  unfold IF_state; infer_instance

/-- Exhaustive partition of `U` into `WF` and `IF_state`. -/
theorem wf_or_if {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    WF r ∨ IF_state r :=
  Classical.em (WF r)

/-- Disjointness of `WF` and `IF_state`. -/
theorem wf_and_if_disjoint {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    ¬(WF r ∧ IF_state r) :=
  fun ⟨h1, h2⟩ => h2 h1

/-- Exhaustive partition of `WF` into `CM` and `EI`. -/
theorem cm_or_ei_of_wf {w_lo w_hi : Nat} (r : RegState w_lo w_hi) (hwf : WF r) :
    CM r ∨ EI r := by
  by_cases hex : ∃ x, gammaReg r x
  · exact Or.inl ⟨hwf, hex⟩
  · exact Or.inr ⟨hwf, fun x hx => hex ⟨x, hx⟩⟩

/-- Disjointness of `CM` and `EI`. -/
theorem cm_and_ei_disjoint {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    ¬(CM r ∧ EI r) := by
  rintro ⟨⟨_, ⟨x, hx⟩⟩, ⟨_, hno⟩⟩
  exact hno x hx

/-- Three-way exhaustive partition of the syntactic universe `U = CM ⊔ EI ⊔ IF`. -/
theorem universe_partition_trichotomy {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    CM r ∨ EI r ∨ IF_state r := by
  rcases wf_or_if r with hwf | hif
  · rcases cm_or_ei_of_wf r hwf with hcm | hei
    · exact Or.inl hcm
    · exact Or.inr (Or.inl hei)
  · exact Or.inr (Or.inr hif)

/-- In `WF`, every individual component domain is non-empty on its own (§3.2). -/
theorem wf_domains_individually_nonempty {w_lo w_hi : Nat} (r : RegState w_lo w_hi) (hwf : WF r) :
    (∃ x : BitVec (w_lo + w_hi), gammaU r.u64 x) ∧
    (∃ x : BitVec (w_lo + w_hi), gammaS r.s64 x) ∧
    (∃ x : BitVec (w_lo + w_hi), gammaUSub r.u32 x) ∧
    (∃ x : BitVec (w_lo + w_hi), gammaSSub r.s32 x) ∧
    (∃ x : BitVec (w_lo + w_hi), gammaTnum r.tnum x) := by
  rcases hwf with ⟨hu64, hs64, hu32, hs32, htnum⟩
  refine ⟨⟨r.u64.min, BitVec.le_refl _, hu64⟩,
          ⟨r.s64.smin, ?_, hs64⟩,
          ⟨mkWord 0#w_hi r.u32.min, ?_⟩,
          ⟨mkWord 0#w_hi r.s32.smin, ?_⟩,
          ⟨r.tnum.v, self_mem_gammaTnum r.tnum htnum⟩⟩
  · rw [BitVec.sle_iff_toInt_le]; exact Int.le_refl _
  · unfold gammaUSub gammaU
    rw [loSlice_mkWord]
    exact ⟨BitVec.le_refl _, hu32⟩
  · unfold gammaSSub gammaS
    rw [loSlice_mkWord]
    refine ⟨?_, hs32⟩
    rw [BitVec.sle_iff_toInt_le]; exact Int.le_refl _

/-- Every Ill-Formed state `R ∈ IF_state` has an empty concretization (`γ_P(R) = ∅`). -/
theorem if_state_concretization_empty {w_lo w_hi : Nat} (r : RegState w_lo w_hi)
    (hif : IF_state r) :
    ∀ x : BitVec (w_lo + w_hi), ¬gammaReg r x := by
  intro x ⟨hu64, hs64, hu32, hs32, htnum⟩
  apply hif
  refine ⟨?_, ?_, ?_, ?_, gammaTnum_implies_wf r.tnum x htnum⟩
  · unfold UInterval.wf
    rw [BitVec.le_def]
    have h1 := BitVec.le_def.mp hu64.1
    have h2 := BitVec.le_def.mp hu64.2
    omega
  · unfold SInterval.wf
    rw [BitVec.sle_iff_toInt_le]
    have h1 := BitVec.sle_iff_toInt_le.mp hs64.1
    have h2 := BitVec.sle_iff_toInt_le.mp hs64.2
    omega
  · unfold UInterval.wf
    rw [BitVec.le_def]
    have h1 := BitVec.le_def.mp hu32.1
    have h2 := BitVec.le_def.mp hu32.2
    omega
  · unfold SInterval.wf
    rw [BitVec.sle_iff_toInt_le]
    have h1 := BitVec.sle_iff_toInt_le.mp hs32.1
    have h2 := BitVec.sle_iff_toInt_le.mp hs32.2
    omega

/-- Any state in `EI ∪ IF` has an empty concretization (`γ_P(R) = ∅`). -/
theorem ei_or_if_concretization_empty {w_lo w_hi : Nat} (r : RegState w_lo w_hi)
    (h : EI r ∨ IF_state r) :
    ∀ x : BitVec (w_lo + w_hi), ¬gammaReg r x := by
  rcases h with ⟨_, hno⟩ | hif
  · exact hno
  · exact if_state_concretization_empty r hif

/-- Contrapositive: any state with a concrete witness `x ∈ γ_P(R)` belongs to `CM`. -/
theorem mem_gammaReg_implies_cm {w_lo w_hi : Nat} (r : RegState w_lo w_hi)
    (x : BitVec (w_lo + w_hi)) (hx : gammaReg r x) :
    CM r := by
  rcases wf_or_if r with hwf | hif
  · exact ⟨hwf, ⟨x, hx⟩⟩
  · exact absurd hx (if_state_concretization_empty r hif x)

/-- **Theorem 3.1 (Dead Branch Principle — Single-Register Form)**:
    For any bitwidths `w_lo, w_hi`, if `r_u ∈ CM` and a sound branch refinement
    operator `refine` for condition `C` produces `r_v ∈ EI ∪ IF_state`, then no concrete
    execution reaching `u` can satisfy `C` (`∀ x ∈ γ_P(r_u), ¬C x`). -/
theorem dead_branch_principle_single {w_lo w_hi : Nat}
    (C : BitVec (w_lo + w_hi) → Prop)
    (refine : RegState w_lo w_hi → RegState w_lo w_hi)
    (h_sound : ∀ (r : RegState w_lo w_hi) (x : BitVec (w_lo + w_hi)),
      gammaReg r x → C x → gammaReg (refine r) x)
    (r_u : RegState w_lo w_hi)
    (_h_cm : CM r_u)
    (h_dead : EI (refine r_u) ∨ IF_state (refine r_u)) :
    ∀ x : BitVec (w_lo + w_hi), gammaReg r_u x → ¬C x := by
  intro x hx hC
  have hx_v : gammaReg (refine r_u) x := h_sound r_u x hx hC
  exact ei_or_if_concretization_empty (refine r_u) h_dead x hx_v

/-- **Theorem 3.1 (Dead Branch Principle — Binary Form, Equation 16)**:
    For any bitwidths `w_lo, w_hi`, let `R_1, R_2 ∈ CM` be the abstract states of the
    branch operand registers at node `u`. If refining along branch condition `C(x, y)`
    yields `(R_1', R_2')` where `R_1' ∈ EI ∪ IF` or `R_2' ∈ EI ∪ IF`, then the branch
    is unreachable at runtime: `{(x, y) ∈ γ_P(R_1) × γ_P(R_2) | C(x, y)} = ∅`. -/
theorem dead_branch_principle_binary {w_lo w_hi : Nat}
    (C : BitVec (w_lo + w_hi) → BitVec (w_lo + w_hi) → Prop)
    (refine : RegState w_lo w_hi → RegState w_lo w_hi → RegState w_lo w_hi × RegState w_lo w_hi)
    (h_sound : ∀ (r1 r2 : RegState w_lo w_hi) (x y : BitVec (w_lo + w_hi)),
      gammaReg r1 x → gammaReg r2 y → C x y →
        gammaReg (refine r1 r2).1 x ∧ gammaReg (refine r1 r2).2 y)
    (r1 r2 : RegState w_lo w_hi)
    (_h_cm1 : CM r1) (_h_cm2 : CM r2)
    (h_dead : (EI (refine r1 r2).1 ∨ IF_state (refine r1 r2).1) ∨
              (EI (refine r1 r2).2 ∨ IF_state (refine r1 r2).2)) :
    ∀ (x y : BitVec (w_lo + w_hi)), gammaReg r1 x → gammaReg r2 y → ¬C x y := by
  intro x y hx hy hC
  obtain ⟨hx', hy'⟩ := h_sound r1 r2 x y hx hy hC
  rcases h_dead with h1 | h2
  · exact ei_or_if_concretization_empty (refine r1 r2).1 h1 x hx'
  · exact ei_or_if_concretization_empty (refine r1 r2).2 h2 y hy'

/-! ### §3.1 Motivating Invariant-Violation Transition Example (`CM → EI → IF`) -/

/-- Initial register state `R_0 ∈ CM`: `u64 = [0, 15]`, `tnum = (15, 0)` (constant 15). -/
def motivating_R0 : RegState 32 32 where
  u64  := ⟨0#64, 15#64⟩
  s64  := ⟨0#64, 15#64⟩
  u32  := ⟨0#32, 15#32⟩
  s32  := ⟨0#32, 15#32⟩
  tnum := ⟨15#64, 0#64⟩

/-- After taking the infeasible branch `r1 ≤_u 10`, interval refinement produces
    `R_1` with `u64 = [0, 10]` while `tnum = (15, 0)` remains 15 (`CM → EI`). -/
def motivating_R1_EI : RegState 32 32 :=
  { motivating_R0 with u64 := ⟨0#64, 10#64⟩ }

/-- Subsequent `reg_bounds_sync` tightens `umin ← max(0, tnum.v) = 15`,
    yielding `u64 = [15, 10]` with `umin = 15 > 10 = umax` (`EI → IF`). -/
def motivating_R2_IF : RegState 32 32 :=
  { motivating_R1_EI with u64 := ⟨15#64, 10#64⟩ }

theorem motivating_transition_chain :
    CM motivating_R0 ∧ EI motivating_R1_EI ∧ IF_state motivating_R2_IF := by
  refine ⟨⟨by decide, ⟨15#64, by decide⟩⟩, ⟨by decide, ?_⟩, by decide⟩
  intro x ⟨hu64, _, _, _, htnum⟩
  have h1 : x ≤ 10#64 := hu64.2
  have h2 : 15#64 ≤ x := gammaTnum_ge_v motivating_R1_EI.tnum x htnum
  simp [BitVec.le_def] at h1 h2
  omega

/-!
================================================================================
## §4. Abstract Step Functions, Theorem 4.2, and Parametric `tnum_step`
================================================================================
We formalize:
- §4.1: Soundness vs. incompleteness of bounding-box intersection for `Tnum w`.
- §4.2: **Definition 4.1 (Abstract Step Function, Eq. 17)** and **Theorem 4.2
  (One-Step Interval Intersection, Eq. 18)** for an arbitrary abstract domain over `BitVec w`.
- §4.2: Parametric `tnum_step` for arbitrary bitwidth `w : Nat`, its specification
  **Equation (19)** (`tnum_step_spec`), and the Figure 2(a,b) walkthroughs.
-/

/-- §4.1: The bounding box `[t.v, t.v | t.m]` is a sound over-approximation of `γ_tnum(t)`
    for every bitwidth `w : Nat`. -/
theorem tnum_bounding_box_sound {w : Nat} (t : Tnum w) (x : BitVec w)
    (hx : gammaTnum t x) :
    gammaU ⟨t.v, t.v ||| t.m⟩ x :=
  ⟨gammaTnum_ge_v t x hx, gammaTnum_le_max t x hx⟩

/-- §4.1 Counterexample to Helly's property / bounding-box completeness:
    `I = [1, 3]` and `t = (0, 4)` (representing `{0, 4}`) have overlapping bounding boxes
    (`max(1, 0) = 1 ≤ 3 = min(3, 4)`), yet their intersection `[1, 3] ∩ {0, 4}` is empty. -/
theorem tnum_bounding_box_incomplete :
    let I : UInterval 8 := ⟨1#8, 3#8⟩
    let t : Tnum 8 := ⟨0#8, 4#8⟩
    (t.v ≤ I.max ∧ I.min ≤ (t.v ||| t.m)) ∧
    ∀ x : BitVec 8, ¬(gammaU I x ∧ gammaTnum t x) := by
  decide

/-- **Definition 4.1 (Abstract Step Function, Equation 17)**:
    Given an abstract domain `A` over `BitVec w` with concretization `γ` and maximum
    function `maxElem`, `step` is an abstract step function if for every `a` and every
    `z < maxElem a`, `step a z` is the smallest element of `γ a` strictly greater than `z`. -/
structure IsAbstractStepFn {w : Nat} {A : Type}
    (gamma : A → BitVec w → Prop)
    (maxElem : A → BitVec w)
    (step : A → BitVec w → BitVec w) : Prop where
  mem_le_max : ∀ (a : A) (x : BitVec w), gamma a x → x ≤ maxElem a
  step_mem : ∀ (a : A) (z : BitVec w), z < maxElem a → gamma a (step a z)
  step_gt : ∀ (a : A) (z : BitVec w), z < maxElem a → z < step a z
  step_minimal : ∀ (a : A) (z y : BitVec w),
    z < maxElem a → gamma a y → z < y → step a z ≤ y

/-- **Theorem 4.2 (One-Step Interval Intersection, Equation 18)**:
    For any bitwidth `w : Nat`, any abstract domain `A` equipped with an abstract step
    function `step`, and any well-formed unsigned interval `I = [L, R]` (`L ≤ R`),
    `I` intersects `γ(a)` if and only if either `L ∈ γ(a)` or (`L < maxElem a` and `step(a, L) ≤ R`). -/
theorem one_step_interval_intersection {w : Nat} {A : Type}
    {gamma : A → BitVec w → Prop}
    {maxElem : A → BitVec w}
    {step : A → BitVec w → BitVec w}
    (hstep : IsAbstractStepFn gamma maxElem step)
    (a : A) (I : UInterval w) (hwf : I.wf) :
    (∃ x : BitVec w, gammaU I x ∧ gamma a x) ↔
      (gamma a I.min ∨ (I.min < maxElem a ∧ step a I.min ≤ I.max)) := by
  constructor
  · rintro ⟨x, ⟨hL, hR⟩, hxa⟩
    by_cases heq : x = I.min
    · subst heq
      exact Or.inl hxa
    · right
      have hlt : I.min < x := by
        rw [BitVec.le_def] at hL
        rw [BitVec.lt_def]
        have hne : x.toNat ≠ I.min.toNat := fun h => heq (BitVec.eq_of_toNat_eq h)
        omega
      have hmax : x ≤ maxElem a := hstep.mem_le_max a x hxa
      have hL_max : I.min < maxElem a := by
        rw [BitVec.lt_def] at hlt ⊢
        rw [BitVec.le_def] at hmax
        omega
      have hmin_step : step a I.min ≤ x := hstep.step_minimal a I.min x hL_max hxa hlt
      refine ⟨hL_max, ?_⟩
      rw [BitVec.le_def] at hmin_step hR ⊢
      omega
  · rintro (hL_mem | ⟨hL_max, hstep_le⟩)
    · exact ⟨I.min, ⟨BitVec.le_refl I.min, hwf⟩, hL_mem⟩
    · refine ⟨step a I.min, ⟨?_, hstep_le⟩, hstep.step_mem a I.min hL_max⟩
      have hgt := hstep.step_gt a I.min hL_max
      rw [BitVec.lt_def] at hgt
      rw [BitVec.le_def]
      omega

/-- **Parametric `tnum_step` for arbitrary bitwidth `w : Nat` (§4.2, Algorithm 1 / Eq. 19)**:
    Given a tristate number `t = (v, m)` and query point `z`, computes the smallest
    `x ∈ γ_tnum(t)` such that `z <_u x` (whenever `z <_u (t.v | t.m)`). -/
def tnum_step {w : Nat} (t : Tnum w) (z : BitVec w) : BitVec w :=
  match w with
  | 0 => 0#0
  | w' + 1 =>
    let bz := z.msb
    let z_lo := z.setWidth w'
    let bv := t.v.msb
    let v_lo := t.v.setWidth w'
    let m_lo := t.m.setWidth w'
    let t_lo : Tnum w' := ⟨v_lo, m_lo⟩
    if bz then
      BitVec.cons true (tnum_step t_lo z_lo)
    else if bv then
      BitVec.cons true v_lo
    else if z_lo < (v_lo ||| m_lo) then
      BitVec.cons false (tnum_step t_lo z_lo)
    else
      BitVec.cons true v_lo

/-- **Equation (19): Soundness, Strict Progress, and Minimality of `tnum_step`**
    proved parametrically for **all bitwidths `w : Nat`**. -/
theorem tnum_step_spec {w : Nat} (t : Tnum w) (z : BitVec w)
    (hwf : t.wf) (hlt : z < (t.v ||| t.m)) :
    gammaTnum t (tnum_step t z) ∧
    z < tnum_step t z ∧
    ∀ y : BitVec w, gammaTnum t y → z < y → tnum_step t z ≤ y := by
  induction w with
  | zero =>
    rw [BitVec.lt_def] at hlt
    have := z.isLt
    omega
  | succ w' ih =>
    dsimp [tnum_step]
    rw [tnum_wf_succ_iff] at hwf
    rw [lt_succ_iff, msb_or, setWidth_or] at hlt
    cases hbz : z.msb
    · -- Case 1: z.msb = false
      simp only [Bool.false_eq_true, ↓reduceIte]
      cases hbv : t.v.msb
      · -- Subcase 1a: t.v.msb = false
        simp only [Bool.false_eq_true, ↓reduceIte]
        by_cases h_zlo : z.setWidth w' < (t.v.setWidth w' ||| t.m.setWidth w')
        · -- Lower bits can advance within the 0-MSB half-space
          simp only [h_zlo, ↓reduceIte]
          obtain ⟨h_mem_lo, h_gt_lo, h_min_lo⟩ :=
            ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ (z.setWidth w') hwf.2 h_zlo
          refine ⟨?_, ?_, ?_⟩
          · rw [gammaTnum_cons_iff, hbv]
            exact ⟨rfl, h_mem_lo⟩
          · rw [lt_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons, hbz]
            exact Or.inr ⟨rfl, h_gt_lo⟩
          · intro y hy hzy
            rw [gammaTnum_succ_iff] at hy
            rw [lt_succ_iff, hbz] at hzy
            rw [le_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons]
            cases hy_msb : y.msb
            · right
              refine ⟨rfl, h_min_lo (y.setWidth w') hy.2 ?_⟩
              rcases hzy with ⟨_, h_abs⟩ | ⟨_, h_lt_lo⟩
              · rw [hy_msb] at h_abs; contradiction
              · exact h_lt_lo
            · exact Or.inl ⟨rfl, rfl⟩
        · -- Lower bits exhausted (`z_lo ≥ v_lo | m_lo`), carry into unknown MSB = 1
          simp only [h_zlo, ↓reduceIte]
          have hbm : t.m.msb = true := by
            rcases hlt with ⟨_, h_or⟩ | ⟨_, h_lo_lt⟩
            · rw [hbv, Bool.false_or] at h_or; exact h_or
            · exact absurd h_lo_lt h_zlo
          refine ⟨?_, ?_, ?_⟩
          · rw [gammaTnum_cons_iff, hbv, hbm]
            exact ⟨rfl, self_mem_gammaTnum ⟨t.v.setWidth w', t.m.setWidth w'⟩ hwf.2⟩
          · rw [lt_succ_iff, BitVec.msb_cons, hbz]
            exact Or.inl ⟨rfl, rfl⟩
          · intro y hy hzy
            rw [gammaTnum_succ_iff] at hy
            rw [lt_succ_iff, hbz] at hzy
            rw [le_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons]
            cases hy_msb : y.msb
            · exfalso
              have hy_le : y.setWidth w' ≤ (t.v.setWidth w' ||| t.m.setWidth w') :=
                gammaTnum_le_max ⟨t.v.setWidth w', t.m.setWidth w'⟩ (y.setWidth w') hy.2
              rcases hzy with ⟨_, h_abs⟩ | ⟨_, h_lt_lo⟩
              · rw [hy_msb] at h_abs; contradiction
              · have : z.setWidth w' < (t.v.setWidth w' ||| t.m.setWidth w') := by
                  rw [BitVec.lt_def] at h_lt_lo ⊢
                  rw [BitVec.le_def] at hy_le
                  omega
                exact h_zlo this
            · exact Or.inr ⟨rfl, gammaTnum_ge_v ⟨t.v.setWidth w', t.m.setWidth w'⟩ (y.setWidth w') hy.2⟩
      · -- Subcase 1b: t.v.msb = true (fixed 1 bit > z.msb = 0; jump directly to t.v)
        simp only [↓reduceIte]
        have hbm : t.m.msb = false := by
          have h1 := hwf.1
          rw [hbv, Bool.true_and] at h1
          exact h1
        refine ⟨?_, ?_, ?_⟩
        · rw [gammaTnum_cons_iff, hbv, hbm]
          exact ⟨rfl, self_mem_gammaTnum ⟨t.v.setWidth w', t.m.setWidth w'⟩ hwf.2⟩
        · rw [lt_succ_iff, BitVec.msb_cons, hbz]
          exact Or.inl ⟨rfl, rfl⟩
        · intro y hy hzy
          rw [gammaTnum_succ_iff] at hy
          rw [le_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons]
          have hy_msb : y.msb = true := by
            have h1 := hy.1
            rw [hbv, hbm] at h1
            simpa using h1
          rw [hy_msb]
          exact Or.inr ⟨rfl, gammaTnum_ge_v ⟨t.v.setWidth w', t.m.setWidth w'⟩ (y.setWidth w') hy.2⟩
    · -- Case 2: z.msb = true
      simp only [↓reduceIte]
      have h_or_and_lt : (t.v.msb || t.m.msb) = true ∧
          z.setWidth w' < (t.v.setWidth w' ||| t.m.setWidth w') := by
        rcases hlt with ⟨h_abs, _⟩ | ⟨h_eq, h_lo_lt⟩
        · rw [hbz] at h_abs; contradiction
        · rw [hbz] at h_eq; exact ⟨h_eq.symm, h_lo_lt⟩
      obtain ⟨h_mem_lo, h_gt_lo, h_min_lo⟩ :=
        ih ⟨t.v.setWidth w', t.m.setWidth w'⟩ (z.setWidth w') hwf.2 h_or_and_lt.2
      refine ⟨?_, ?_, ?_⟩
      · rw [gammaTnum_cons_iff]
        refine ⟨?_, h_mem_lo⟩
        have h1 := hwf.1
        have h2 := h_or_and_lt.1
        revert h1 h2
        cases t.v.msb <;> cases t.m.msb <;> decide
      · rw [lt_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons, hbz]
        exact Or.inr ⟨rfl, h_gt_lo⟩
      · intro y hy hzy
        rw [gammaTnum_succ_iff] at hy
        rw [lt_succ_iff, hbz] at hzy
        rw [le_succ_iff, BitVec.msb_cons, BitVec.setWidth_cons]
        rcases hzy with ⟨h_abs, _⟩ | ⟨hy_msb, h_lt_lo⟩
        · contradiction
        · rw [← hy_msb]
          exact Or.inr ⟨rfl, h_min_lo (y.setWidth w') hy.2 h_lt_lo⟩

/-- `tnum_step` satisfies Definition 4.1 (`IsAbstractStepFn`) on the subtype of well-formed
    `w`-bit tnums for every bitwidth `w : Nat`. -/
theorem tnum_step_is_abstract_step_fn (w : Nat) :
    IsAbstractStepFn
      (fun (t : { t : Tnum w // t.wf }) x => gammaTnum t.val x)
      (fun (t : { t : Tnum w // t.wf }) => t.val.v ||| t.val.m)
      (fun (t : { t : Tnum w // t.wf }) z => tnum_step t.val z) where
  mem_le_max t x hx := gammaTnum_le_max t.val x hx
  step_mem t z hlt := (tnum_step_spec t.val z t.property hlt).1
  step_gt t z hlt := (tnum_step_spec t.val z t.property hlt).2.1
  step_minimal t z y hlt hy hzy := (tnum_step_spec t.val z t.property hlt).2.2 y hy hzy

/-- **Corollary of Theorem 4.2 & Equation (19)**: One-Step Interval Intersection for `Tnum w`
    at arbitrary bitwidth `w : Nat`. -/
theorem tnum_one_step_interval_intersection {w : Nat} (t : Tnum w) (I : UInterval w)
    (ht : t.wf) (hI : I.wf) :
    (∃ x : BitVec w, gammaU I x ∧ gammaTnum t x) ↔
      (gammaTnum t I.min ∨ (I.min < (t.v ||| t.m) ∧ tnum_step t I.min ≤ I.max)) :=
  one_step_interval_intersection (tnum_step_is_abstract_step_fn w) ⟨t, ht⟩ I hI

/-! ### Figure 2(a) & Figure 2(b) Walkthroughs (`w = 8`) -/

/-- **Figure 2(a) Walkthrough (`w = 8`)**:
    `t = 10xx100x_2` (`v = 136 = 0b10001000`, `m = 49 = 0b00110001`), `z = 130 = 0b10000010`.
    Fixed-bit divergence at bit 3 (`z[3] = 0, t.v[3] = 1`) steps `z` to `136 = 0b10001000`. -/
theorem fig2a_tnum_step_walkthrough :
    let t : Tnum 8 := ⟨136#8, 49#8⟩
    let z : BitVec 8 := 130#8
    t.wf ∧ tnum_step t z = 136#8 ∧ gammaTnum t 136#8 := by
  decide

/-- **Figure 2(b) Walkthrough (`w = 8`)**:
    `t = 1x1100xx_2` (`v = 176 = 0b10110000`, `m = 67 = 0b01000011`), `z = 189 = 0b10111101`.
    Carry propagation out of bit 3 into unknown bit 6 steps `z` to `240 = 0b11110000`. -/
theorem fig2b_tnum_step_walkthrough :
    let t : Tnum 8 := ⟨176#8, 67#8⟩
    let z : BitVec 8 := 189#8
    t.wf ∧ tnum_step t z = 240#8 ∧ gammaTnum t 240#8 := by
  decide

/-!
================================================================================
## §5. Multi-Domain Set Intersections (Algorithm 2 & Theorem 5.1)
================================================================================
We formalize the general multi-domain intersection algorithm (`multi_domain_intersect`,
Algorithm 2) for an arbitrary list of steppable domains over `BitVec w`, prove its
soundness and completeness for all `w : Nat`, verify the Figure 3(a,b) walkthroughs,
and formalize **Theorem 5.1 (Sufficient Constant-Time Intersection Theorem)**.
-/

/-- §5.1 Interface of an abstract domain over `BitVec w` equipped with an abstract step function. -/
structure SteppableDomain (w : Nat) where
  min : BitVec w
  max : BitVec w
  contains : BitVec w → Bool
  step : BitVec w → BitVec w

/-- Lawfulness of a `SteppableDomain w` (§5.1 requirements (i)–(iii) and Definition 4.1). -/
structure LawfulSteppableDomain {w : Nat} (d : SteppableDomain w) : Prop where
  bounds_sound : ∀ x : BitVec w, d.contains x = true → d.min ≤ x ∧ x ≤ d.max
  step_mem : ∀ z : BitVec w, z < d.max → d.contains (d.step z) = true
  step_gt : ∀ z : BitVec w, z < d.max → z < d.step z
  step_min : ∀ z y : BitVec w, z < d.max → d.contains y = true → z < y → d.step z ≤ y

/-- Canonical `SteppableDomain w` for any `Tnum w`. -/
def tnumSteppableDomain {w : Nat} (t : Tnum w) : SteppableDomain w where
  min := t.v
  max := t.v ||| t.m
  contains := fun x => (x &&& ~~~t.m) == t.v
  step := tnum_step t

/-- Every well-formed `Tnum w` forms a `LawfulSteppableDomain w` for any bitwidth `w : Nat`. -/
theorem tnumSteppableDomain_lawful {w : Nat} (t : Tnum w) (hwf : t.wf) :
    LawfulSteppableDomain (tnumSteppableDomain t) where
  bounds_sound x hx := by
    have hmem : gammaTnum t x := by simpa [tnumSteppableDomain, gammaTnum] using hx
    exact ⟨gammaTnum_ge_v t x hmem, gammaTnum_le_max t x hmem⟩
  step_mem z hlt := by
    have hmem := (tnum_step_spec t z hwf hlt).1
    simpa [tnumSteppableDomain, gammaTnum] using hmem
  step_gt z hlt := (tnum_step_spec t z hwf hlt).2.1
  step_min z y hlt hy hzy := by
    have hmem : gammaTnum t y := by simpa [tnumSteppableDomain, gammaTnum] using hy
    exact (tnum_step_spec t z hwf hlt).2.2 y hmem hzy

/-- Canonical `SteppableDomain w` for any unsigned interval `UInterval w`. -/
def uintervalSteppableDomain {w : Nat} (I : UInterval w) : SteppableDomain w where
  min := I.min
  max := I.max
  contains := fun x => decide (I.min ≤ x ∧ x ≤ I.max)
  step := fun z => if z < I.min then I.min else z + 1#w

/-- Every well-formed `UInterval w` forms a `LawfulSteppableDomain w` for any bitwidth `w : Nat`. -/
theorem uintervalSteppableDomain_lawful {w : Nat} (I : UInterval w) (hwf : I.wf) :
    LawfulSteppableDomain (uintervalSteppableDomain I) where
  bounds_sound x hx := by
    simpa [uintervalSteppableDomain] using hx
  step_mem z hlt := by
    dsimp [uintervalSteppableDomain]
    by_cases hz : z < I.min
    · simp only [hz, ↓reduceIte, decide_eq_true_eq]
      exact ⟨BitVec.le_refl _, hwf⟩
    · simp only [hz, ↓reduceIte, decide_eq_true_eq]
      have h_le : I.min.toNat ≤ z.toNat := by
        rw [BitVec.lt_def] at hz; omega
      have h_lt : z.toNat < I.max.toNat := BitVec.lt_def.mp hlt
      have h_max := I.max.isLt
      have h_add : (z + 1#w).toNat = z.toNat + 1 := by
        rw [BitVec.toNat_add, BitVec.toNat_ofNat]
        have h1 : 1 % 2 ^ w = 1 := Nat.mod_eq_of_lt (by omega)
        rw [h1]
        exact Nat.mod_eq_of_lt (by omega)
      rw [BitVec.le_def, BitVec.le_def, h_add]
      omega
  step_gt z hlt := by
    dsimp [uintervalSteppableDomain]
    by_cases hz : z < I.min
    · simp [hz]
    · simp only [hz, ↓reduceIte]
      have h_lt : z.toNat < I.max.toNat := BitVec.lt_def.mp hlt
      have h_max := I.max.isLt
      have h_add : (z + 1#w).toNat = z.toNat + 1 := by
        rw [BitVec.toNat_add, BitVec.toNat_ofNat]
        have h1 : 1 % 2 ^ w = 1 := Nat.mod_eq_of_lt (by omega)
        rw [h1]
        exact Nat.mod_eq_of_lt (by omega)
      rw [BitVec.lt_def, h_add]
      omega
  step_min z y hlt hy hzy := by
    dsimp [uintervalSteppableDomain] at hy ⊢
    rw [decide_eq_true_eq] at hy
    by_cases hz : z < I.min
    · simp [hz, hy.1]
    · simp only [hz, ↓reduceIte]
      have h_lt : z.toNat < I.max.toNat := BitVec.lt_def.mp hlt
      have h_max := I.max.isLt
      have h_add : (z + 1#w).toNat = z.toNat + 1 := by
        rw [BitVec.toNat_add, BitVec.toNat_ofNat]
        have h1 : 1 % 2 ^ w = 1 := Nat.mod_eq_of_lt (by omega)
        rw [h1]
        exact Nat.mod_eq_of_lt (by omega)
      rw [BitVec.lt_def] at hzy
      rw [BitVec.le_def, h_add]
      omega

/-- Algorithm 2 loop: advances candidate `xc` across disagreeing domains until either
    all domains accept `xc` (`true`) or `xc` exceeds `xmax` / a domain's maximum (`false`). -/
def multiDomainLoop {w : Nat} (ds : List (SteppableDomain w)) (xmax : BitVec w)
    (xc : BitVec w) : Nat → Bool
  | 0 => false
  | fuel + 1 =>
    if xc ≤ xmax then
      match ds.find? (fun d => !d.contains xc) with
      | none => true
      | some d =>
        if xc < d.max then
          multiDomainLoop ds xmax (d.step xc) fuel
        else
          false
    else
      false

/-- Global lower bound `xmin = max_i min(γ_i(a_i))` (Algorithm 2, line 1). -/
def domainMin {w : Nat} (ds : List (SteppableDomain w)) : BitVec w :=
  ds.foldr (fun d acc => if acc ≤ d.min then d.min else acc) (0#w)

/-- Global upper bound `xmax = min_i max(γ_i(a_i))` (Algorithm 2, line 2). -/
def domainMax {w : Nat} (ds : List (SteppableDomain w)) : BitVec w :=
  ds.foldr (fun d acc => if d.max ≤ acc then d.max else acc) (BitVec.allOnes w)

/-- **Algorithm 2 (`multi_domain_intersect`)**:
    General multi-domain set intersection over `BitVec w`. -/
def multi_domain_intersect {w : Nat} (ds : List (SteppableDomain w)) : Bool :=
  let xmin := domainMin ds
  let xmax := domainMax ds
  multiDomainLoop ds xmax xmin (xmax.toNat + 1 - xmin.toNat)

theorem domainMin_le {w : Nat} (ds : List (SteppableDomain w)) (x : BitVec w)
    (hlaw : ∀ d ∈ ds, LawfulSteppableDomain d)
    (hmem : ∀ d ∈ ds, d.contains x = true) :
    domainMin ds ≤ x := by
  induction ds with
  | nil =>
    dsimp [domainMin]
    exact zero_le_bv x
  | cons d tl ih =>
    dsimp [domainMin]
    have hd_law := hlaw d List.mem_cons_self
    have hd_mem := hmem d List.mem_cons_self
    have hd_min : d.min ≤ x := (hd_law.bounds_sound x hd_mem).1
    have htl : domainMin tl ≤ x :=
      ih (fun d' hd' => hlaw d' (List.mem_cons_of_mem d hd'))
         (fun d' hd' => hmem d' (List.mem_cons_of_mem d hd'))
    change (if domainMin tl ≤ d.min then d.min else domainMin tl) ≤ x
    split <;> assumption

theorem le_domainMax {w : Nat} (ds : List (SteppableDomain w)) (x : BitVec w)
    (hlaw : ∀ d ∈ ds, LawfulSteppableDomain d)
    (hmem : ∀ d ∈ ds, d.contains x = true) :
    x ≤ domainMax ds := by
  induction ds with
  | nil =>
    dsimp [domainMax]
    exact le_allOnes x
  | cons d tl ih =>
    dsimp [domainMax]
    have hd_law := hlaw d List.mem_cons_self
    have hd_mem := hmem d List.mem_cons_self
    have hd_max : x ≤ d.max := (hd_law.bounds_sound x hd_mem).2
    have htl : x ≤ domainMax tl :=
      ih (fun d' hd' => hlaw d' (List.mem_cons_of_mem d hd'))
         (fun d' hd' => hmem d' (List.mem_cons_of_mem d hd'))
    change x ≤ (if d.max ≤ domainMax tl then d.max else domainMax tl)
    split <;> assumption

theorem multiDomainLoop_spec {w : Nat} (ds : List (SteppableDomain w))
    (xmax : BitVec w) (hlaw : ∀ d ∈ ds, LawfulSteppableDomain d) :
    ∀ (fuel : Nat) (xc : BitVec w),
      xmax.toNat + 1 - xc.toNat ≤ fuel →
      (multiDomainLoop ds xmax xc fuel = true ↔
        ∃ x : BitVec w, xc ≤ x ∧ x ≤ xmax ∧ ∀ d ∈ ds, d.contains x = true) := by
  intro fuel
  induction fuel with
  | zero =>
    intro xc hfuel
    dsimp [multiDomainLoop]
    simp only [Bool.false_eq_true, false_iff, not_exists, not_and]
    intro x hxc hxmax _
    rw [BitVec.le_def] at hxc hxmax
    omega
  | succ fuel' ih =>
    intro xc hfuel
    dsimp [multiDomainLoop]
    by_cases hle : xc ≤ xmax
    · simp only [hle, ↓reduceIte]
      cases hfind : ds.find? (fun d => !d.contains xc) with
      | none =>
        simp only [true_iff]
        refine ⟨xc, BitVec.le_refl xc, hle, ?_⟩
        intro d hd
        have hnone := List.find?_eq_none.mp hfind d hd
        simpa using hnone
      | some d =>
        dsimp
        have h_in : d ∈ ds := List.mem_of_find?_eq_some hfind
        have h_not_contains : d.contains xc = false := by
          have hpred := List.find?_some hfind
          simpa using hpred
        have hd_law : LawfulSteppableDomain d := hlaw d h_in
        by_cases hlt_max : xc < d.max
        · simp only [hlt_max, ↓reduceIte]
          have h_step_gt : xc < d.step xc := hd_law.step_gt xc hlt_max
          have h_fuel' : xmax.toNat + 1 - (d.step xc).toNat ≤ fuel' := by
            rw [BitVec.le_def] at hle
            rw [BitVec.lt_def] at h_step_gt
            omega
          rw [ih (d.step xc) h_fuel']
          constructor
          · rintro ⟨x, hstep_le, hx_max, hx_all⟩
            refine ⟨x, ?_, hx_max, hx_all⟩
            rw [BitVec.lt_def] at h_step_gt
            rw [BitVec.le_def] at hstep_le ⊢
            omega
          · rintro ⟨x, hxc_le, hx_max, hx_all⟩
            have hx_d : d.contains x = true := hx_all d h_in
            have hxc_lt_x : xc < x := by
              rw [BitVec.le_def] at hxc_le
              rw [BitVec.lt_def]
              have hne : xc ≠ x := by
                intro heq
                rw [heq, hx_d] at h_not_contains
                contradiction
              have hne_nat : xc.toNat ≠ x.toNat := fun h => hne (BitVec.eq_of_toNat_eq h)
              omega
            exact ⟨x, hd_law.step_min xc x hlt_max hx_d hxc_lt_x, hx_max, hx_all⟩
        · simp only [hlt_max, ↓reduceIte, Bool.false_eq_true, false_iff, not_exists, not_and]
          intro x hxc_le _ hx_all
          have hx_d : d.contains x = true := hx_all d h_in
          have hx_le_dmax : x ≤ d.max := (hd_law.bounds_sound x hx_d).2
          have hne : xc ≠ x := by
            intro heq
            rw [heq, hx_d] at h_not_contains
            contradiction
          have h_abs : xc < d.max := by
            rw [BitVec.le_def] at hxc_le hx_le_dmax
            rw [BitVec.lt_def]
            have hne_nat : xc.toNat ≠ x.toNat := fun h => hne (BitVec.eq_of_toNat_eq h)
            omega
          exact hlt_max h_abs
    · simp only [hle, ↓reduceIte, Bool.false_eq_true, false_iff, not_exists, not_and]
      intro x hxc_le hxmax_le _
      apply hle
      rw [BitVec.le_def] at hxc_le hxmax_le ⊢
      omega

/-- **Soundness and Completeness of Algorithm 2 (`multi_domain_intersect`)**:
    For any bitwidth `w : Nat` and any list `ds` of lawful steppable domains over `BitVec w`,
    `multi_domain_intersect ds = true` if and only if all domains in `ds` share a common
    concrete value `x`. -/
theorem multi_domain_intersect_spec {w : Nat} (ds : List (SteppableDomain w))
    (hlaw : ∀ d ∈ ds, LawfulSteppableDomain d) :
    multi_domain_intersect ds = true ↔ ∃ x : BitVec w, ∀ d ∈ ds, d.contains x = true := by
  unfold multi_domain_intersect
  dsimp
  rw [multiDomainLoop_spec ds (domainMax ds) hlaw
      ((domainMax ds).toNat + 1 - (domainMin ds).toNat) (domainMin ds) (Nat.le_refl _)]
  constructor
  · rintro ⟨x, _, _, hx⟩
    exact ⟨x, hx⟩
  · rintro ⟨x, hx⟩
    exact ⟨x, domainMin_le ds x hlaw hx, le_domainMax ds x hlaw hx, hx⟩

/-! ### Theorem 5.1 (Sufficient Constant-Time Intersection Theorem, §5.2) -/

/-- Key Invariant (2) in Proof of Theorem 5.1 (§5.2):
    Whenever domain `d1` steps from `xc` to `xc' = d1.step xc` (with `xc < d1.max`),
    `d1` is guaranteed to contain `xc'` (`d1.contains (d1.step xc) = true`), so `d1`
    cannot reject `xc'` in the immediately following iteration unless another domain `d_j`
    steps `xc'` first. -/
theorem d1_never_rejects_own_step {w : Nat} (d1 : SteppableDomain w)
    (hlaw : LawfulSteppableDomain d1) (xc : BitVec w) (hlt : xc < d1.max) :
    (!d1.contains (d1.step xc)) = false := by
  rw [hlaw.step_mem xc hlt]
  rfl

/-- Unrolling Multi-Domain Stepping into One-Step Interval Queries (§5.2):
    When domains `A_2, ..., A_k` have bounded discontinuities (`δ_j = O(1)`), their
    intersection decomposes into a finite list `intervals : List (UInterval w)` of at most
    `C = ∏_{j=2}^k (δ_j + 1) = O(1)` contiguous intervals. Checking whether `A_1`
    intersects any `I ∈ intervals` via One-Step Interval Intersection (Theorem 4.2)
    is sound and complete for the full multi-domain intersection in `O(1)` time. -/
def unrolledIntervalListIntersect {w : Nat} (d1 : SteppableDomain w)
    (intervals : List (UInterval w)) : Bool :=
  intervals.any (fun I => d1.contains I.min || (decide (I.min < d1.max) && decide (d1.step I.min ≤ I.max)))

theorem unrolledIntervalListIntersect_spec {w : Nat} (d1 : SteppableDomain w)
    (intervals : List (UInterval w))
    (hlaw1 : LawfulSteppableDomain d1)
    (hwf_int : ∀ I ∈ intervals, I.wf) :
    unrolledIntervalListIntersect d1 intervals = true ↔
      ∃ x : BitVec w, d1.contains x = true ∧ ∃ I ∈ intervals, gammaU I x := by
  unfold unrolledIntervalListIntersect
  rw [List.any_eq_true]
  have hstep : IsAbstractStepFn (fun (_ : Unit) x => d1.contains x = true)
      (fun _ => d1.max) (fun _ => d1.step) := {
    mem_le_max := fun _ x hx => (hlaw1.bounds_sound x hx).2
    step_mem := fun _ z hlt => hlaw1.step_mem z hlt
    step_gt := fun _ z hlt => hlaw1.step_gt z hlt
    step_minimal := fun _ z y hlt hy hzy => hlaw1.step_min z y hlt hy hzy
  }
  constructor
  · rintro ⟨I, hI_mem, hcond⟩
    have hI_wf := hwf_int I hI_mem
    have h_or : d1.contains I.min = true ∨ (I.min < d1.max ∧ d1.step I.min ≤ I.max) := by
      simpa [Bool.or_eq_true, Bool.and_eq_true, decide_eq_true_eq] using hcond
    obtain ⟨x, hxI, hxd1⟩ := (one_step_interval_intersection hstep () I hI_wf).mpr h_or
    exact ⟨x, hxd1, ⟨I, hI_mem, hxI⟩⟩
  · rintro ⟨x, hxd1, ⟨I, hI_mem, hxI⟩⟩
    have hI_wf := hwf_int I hI_mem
    have h_or := (one_step_interval_intersection hstep () I hI_wf).mp ⟨x, hxI, hxd1⟩
    refine ⟨I, hI_mem, ?_⟩
    simpa [Bool.or_eq_true, Bool.and_eq_true, decide_eq_true_eq] using h_or

/-! ### Figure 3(a) & Figure 3(b) Walkthroughs of Algorithm 2 (`w = 8`) -/

/-- Domain `D_1 = {1, 2, 5, 6, 9, 10}` (`t = (1, 12)` shifted, or explicit 2-discontinuity set),
    `D_2 = {0, 3, 4, 5, 9, 10}`, and `D_3 = [2, 10]` (Figure 3a) vs `D_3' = [2, 7]` (Figure 3b). -/
def fig3_D1 : SteppableDomain 8 where
  min := 1#8
  max := 10#8
  contains := fun x => x == 1#8 || x == 2#8 || x == 5#8 || x == 6#8 || x == 9#8 || x == 10#8
  step := fun z =>
    if z < 1#8 then 1#8
    else if z < 2#8 then 2#8
    else if z < 5#8 then 5#8
    else if z < 6#8 then 6#8
    else if z < 9#8 then 9#8
    else 10#8

def fig3_D2 : SteppableDomain 8 where
  min := 0#8
  max := 10#8
  contains := fun x => x == 0#8 || x == 3#8 || x == 4#8 || x == 5#8 || x == 9#8 || x == 10#8
  step := fun z =>
    if z < 0#8 then 0#8
    else if z < 3#8 then 3#8
    else if z < 4#8 then 4#8
    else if z < 5#8 then 5#8
    else if z < 9#8 then 9#8
    else 10#8

/-- **Figure 3(a) Walkthrough**: `D_1 ∩ D_2 ∩ [2, 10]` steps `x_c : 2 → 3 → 5` (or `2 → 5 → 9`)
    and finds a non-empty intersection (`true`). -/
theorem fig3a_walkthrough :
    multi_domain_intersect [fig3_D1, fig3_D2, uintervalSteppableDomain ⟨2#8, 10#8⟩] = true := by
  decide

/-- **Figure 3(b) Walkthrough**: `D_1 ∩ D_2` restricted to `{1,2,9,10}` and `{0,3,4,9,10}`
    against `D_3 = [2, 7]` steps past `x_max = 7` to `9` and returns `false`. -/
theorem fig3b_walkthrough :
    let d1' : SteppableDomain 8 := {
      min := 1#8, max := 10#8,
      contains := fun x => x == 1#8 || x == 2#8 || x == 9#8 || x == 10#8,
      step := fun z => if z < 1#8 then 1#8 else if z < 2#8 then 2#8 else if z < 9#8 then 9#8 else 10#8
    }
    let d2' : SteppableDomain 8 := {
      min := 0#8, max := 10#8,
      contains := fun x => x == 0#8 || x == 5#8 || x == 6#8 || x == 9#8 || x == 10#8,
      step := fun z => if z < 0#8 then 0#8 else if z < 5#8 then 5#8 else if z < 6#8 then 6#8 else if z < 9#8 then 9#8 else 10#8
    }
    multi_domain_intersect [d1', d2', uintervalSteppableDomain ⟨2#8, 7#8⟩] = false := by
  decide

/-!
================================================================================
## §6. Allwise Set Intersection in eBPF (Parametric in `w_lo, w_hi : Nat`)
================================================================================
We now formalize Section 6 of `pldi.pdf` completely parametrically in `w_lo : Nat`
(lower subregister width) and `w_hi : Nat` (upper prefix width):
- §6.1: Signed-to-Unsigned Zero-Crossing Split (Equation 20), Subregister Periodicity
  (Equation 21), Tnum Splitting (Equation 22), and Subspace Projection (Figure 4).
- §6.2: The 3-stage `reg_bounds_intersect` pipeline (Equations 23–28) and the
  **Main Soundness & Completeness Theorem (`reg_bounds_intersect_sound_and_complete`)**.
- §6.3: Dead-branch resolution (`simulate_both_branches_taken`) and its soundness theorem.
-/

/-! ### §6.1.1 Parametric Signed Interval Zero-Crossing Split (Equation 20) -/

/-- Does a `w`-bit signed interval `[smin, smax]_s` cross zero (`smin <_s 0 ≤_s smax`)? -/
def SInterval.crossesZero {w : Nat} (I : SInterval w) : Bool :=
  I.smin.slt 0#w && (0#w).sle I.smax

theorem toInt_zero {w : Nat} : (0#w).toInt = 0 := by
  rw [BitVec.toInt_eq_toNat_cond]
  simp only [BitVec.toNat_ofNat, Nat.zero_mod, Nat.mul_zero]
  have : 0 < 2 ^ w := Nat.two_pow_pos w
  split <;> omega

/-- When a well-formed `w`-bit signed interval does **not** cross zero (`0 ∉ (smin, smax]`),
    its two's-complement bit patterns form a single contiguous unsigned interval `[smin, smax]_u`. -/
theorem gammaS_not_crossesZero {w : Nat} (I : SInterval w) (x : BitVec w)
    (hwf : I.wf) (hnc : I.crossesZero = false) :
    gammaS I x ↔ gammaU ⟨I.smin, I.smax⟩ x := by
  dsimp [gammaS, gammaU, SInterval.wf, SInterval.crossesZero] at *
  rw [Bool.and_eq_false_iff] at hnc
  rw [BitVec.sle_iff_toInt_le] at hwf
  rw [BitVec.sle_iff_toInt_le, BitVec.sle_iff_toInt_le, BitVec.le_def, BitVec.le_def]
  rcases hnc with h1 | h2
  · have h1' : ¬(I.smin.toInt < (0#w).toInt) := by
      rw [← BitVec.slt_iff_toInt_lt]; simp [h1]
    rw [toInt_zero] at h1'
    have hmin := BitVec.toInt_eq_toNat_cond I.smin
    have hmax := BitVec.toInt_eq_toNat_cond I.smax
    have hx := BitVec.toInt_eq_toNat_cond x
    have := I.smin.isLt; have := I.smax.isLt; have := x.isLt
    split at hmin <;> split at hmax <;> split at hx <;> omega
  · have h2' : ¬((0#w).toInt ≤ I.smax.toInt) := by
      rw [← BitVec.sle_iff_toInt_le]; simp [h2]
    rw [toInt_zero] at h2'
    have hmin := BitVec.toInt_eq_toNat_cond I.smin
    have hmax := BitVec.toInt_eq_toNat_cond I.smax
    have hx := BitVec.toInt_eq_toNat_cond x
    have := I.smin.isLt; have := I.smax.isLt; have := x.isLt
    split at hmin <;> split at hmax <;> split at hx <;> omega

/-- **Equation (20)**: When a well-formed `w`-bit signed interval crosses zero
    (`smin <_s 0 ≤_s smax`), it splits into two disjoint unsigned intervals:
    `[0, smax]_u` (the non-negative segment) and `[smin, 2^w - 1]_u` (the negative segment). -/
theorem gammaS_crossesZero_split {w : Nat} (I : SInterval w) (x : BitVec w)
    (_hwf : I.wf) (hcz : I.crossesZero = true) :
    gammaS I x ↔ (gammaU ⟨0#w, I.smax⟩ x ∨ gammaU ⟨I.smin, BitVec.allOnes w⟩ x) := by
  dsimp [gammaS, gammaU, SInterval.wf, SInterval.crossesZero] at *
  rw [Bool.and_eq_true] at hcz
  rcases hcz with ⟨h1, h2⟩
  rw [BitVec.slt_iff_toInt_lt, toInt_zero] at h1
  rw [BitVec.sle_iff_toInt_le, toInt_zero] at h2
  rw [BitVec.sle_iff_toInt_le, BitVec.sle_iff_toInt_le]
  rw [BitVec.le_def, BitVec.le_def, BitVec.le_def, BitVec.le_def]
  simp only [BitVec.toNat_ofNat, Nat.zero_mod, BitVec.toNat_allOnes]
  have hmin := BitVec.toInt_eq_toNat_cond I.smin
  have hmax := BitVec.toInt_eq_toNat_cond I.smax
  have hx := BitVec.toInt_eq_toNat_cond x
  have := I.smin.isLt; have := I.smax.isLt; have := x.isLt
  split at hmin <;> split at hmax <;> split at hx <;> omega

/-- Furthermore, the two unsigned intervals `[0, smax]_u` and `[smin, 2^w - 1]_u`
    produced by a zero-crossing split are strictly disjoint (`smax <_u smin`). -/
theorem gammaS_crossesZero_disjoint {w : Nat} (I : SInterval w) (x : BitVec w)
    (hcz : I.crossesZero = true) :
    ¬(gammaU ⟨0#w, I.smax⟩ x ∧ gammaU ⟨I.smin, BitVec.allOnes w⟩ x) := by
  dsimp [gammaU, SInterval.crossesZero] at *
  rw [Bool.and_eq_true] at hcz
  rcases hcz with ⟨h1, h2⟩
  rw [BitVec.slt_iff_toInt_lt, toInt_zero] at h1
  rw [BitVec.sle_iff_toInt_le, toInt_zero] at h2
  rw [BitVec.le_def, BitVec.le_def, BitVec.le_def, BitVec.le_def]
  have hmin := BitVec.toInt_eq_toNat_cond I.smin
  have hmax := BitVec.toInt_eq_toNat_cond I.smax
  have := I.smin.isLt; have := I.smax.isLt; have := x.isLt
  split at hmin <;> split at hmax <;> omega

/-! ### §6.1.2 Parametric Tnum Splitting (`tnumHi` and `tnumLo`, Equation 22) -/

/-- Upper `w_hi`-bit prefix tnum `t_hi = (hiSlice v, hiSlice m)` (§6.1, Equation 22). -/
def tnumHi {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi)) : Tnum w_hi where
  v := hiSlice t.v
  m := hiSlice t.m

/-- Lower `w_lo`-bit subregister tnum `t_lo = (loSlice v, loSlice m)` (§6.1, Equation 22). -/
def tnumLo {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi)) : Tnum w_lo where
  v := loSlice t.v
  m := loSlice t.m

/-- A `(w_lo + w_hi)`-bit tnum is well-formed iff its upper and lower slices are well-formed. -/
theorem tnum_wf_split_iff {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi)) :
    t.wf ↔ (tnumHi t).wf ∧ (tnumLo t).wf := by
  unfold Tnum.wf tnumHi tnumLo
  dsimp
  rw [word_ext_slices, hiSlice_and, loSlice_and, hiSlice_zero, loSlice_zero]

/-- **Equation (22)**: Because tnum constraints are bitwise independent, a `(w_lo + w_hi)`-bit
    word `x` satisfies `t` iff `hiSlice x` satisfies `tnumHi t` and `loSlice x` satisfies `tnumLo t`. -/
theorem gammaTnum_split_iff {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi)) (x : BitVec (w_lo + w_hi)) :
    gammaTnum t x ↔ gammaTnum (tnumHi t) (hiSlice x) ∧ gammaTnum (tnumLo t) (loSlice x) := by
  unfold gammaTnum tnumHi tnumLo
  dsimp
  rw [word_ext_slices, hiSlice_and, loSlice_and, hiSlice_not, loSlice_not]

/-! ### §6.1.3 Parametric Subspace Projection (`SubspaceBox` & `projectInterval`, Figure 4) -/

/-- A 2D Cartesian box `kRange × subRange` representing a contiguous range of `w_hi`-bit
    subspace indices `k ∈ [k_min, k_max]` paired with a `w_lo`-bit subregister interval. -/
structure SubspaceBox (w_lo w_hi : Nat) where
  kRange   : UInterval w_hi
  subRange : UInterval w_lo
  deriving DecidableEq, Repr

def SubspaceBox.wf {w_lo w_hi : Nat} (B : SubspaceBox w_lo w_hi) : Prop :=
  B.kRange.wf ∧ B.subRange.wf

def gammaBox {w_lo w_hi : Nat} (B : SubspaceBox w_lo w_hi) (x : BitVec (w_lo + w_hi)) : Prop :=
  gammaU B.kRange (hiSlice x) ∧ gammaU B.subRange (loSlice x)

/-- **Subspace Projection (§6.1 Cases 1 & 2, Figure 4, Equation 25)**:
    Projects a `(w_lo + w_hi)`-bit unsigned interval `I = [L, R]` onto `w_lo`-bit subspaces:
    - **Case 1 (`k_start == k_end`)**: Single box `([k_start, k_start], [r_start, r_end])`.
    - **Case 2 (`k_start < k_end`)**: Up to 3 boxes:
      head `([k_start, k_start], [r_start, 2^w_lo - 1])`,
      optional interior `([k_start + 1, k_end - 1], [0, 2^w_lo - 1])`,
      and tail `([k_end, k_end], [0, r_end])`. -/
def projectInterval {w_lo w_hi : Nat} (I : UInterval (w_lo + w_hi)) : List (SubspaceBox w_lo w_hi) :=
  let k_start := hiSlice I.min
  let r_start := loSlice I.min
  let k_end := hiSlice I.max
  let r_end := loSlice I.max
  if k_start == k_end then
    [⟨⟨k_start, k_start⟩, ⟨r_start, r_end⟩⟩]
  else
    let b_head : SubspaceBox w_lo w_hi := ⟨⟨k_start, k_start⟩, ⟨r_start, BitVec.allOnes w_lo⟩⟩
    let b_tail : SubspaceBox w_lo w_hi := ⟨⟨k_end, k_end⟩, ⟨0#w_lo, r_end⟩⟩
    if k_start.toNat + 1 < k_end.toNat then
      let b_mid : SubspaceBox w_lo w_hi :=
        ⟨⟨BitVec.ofNat w_hi (k_start.toNat + 1), BitVec.ofNat w_hi (k_end.toNat - 1)⟩,
         ⟨0#w_lo, BitVec.allOnes w_lo⟩⟩
      [b_head, b_mid, b_tail]
    else
      [b_head, b_tail]

theorem projectInterval_length_le_three {w_lo w_hi : Nat} (I : UInterval (w_lo + w_hi)) :
    (projectInterval I).length ≤ 3 := by
  dsimp [projectInterval]
  split
  · simp
  · split <;> simp

theorem projectInterval_wf {w_lo w_hi : Nat} (I : UInterval (w_lo + w_hi)) (hwf : I.wf) :
    ∀ B ∈ projectInterval I, B.wf := by
  dsimp [projectInterval, UInterval.wf] at hwf ⊢
  rw [word_le_iff] at hwf
  by_cases hk : (hiSlice I.min == hiSlice I.max) = true
  · simp only [hk, ↓reduceIte, List.mem_singleton]
    rintro B rfl
    have heq : hiSlice I.min = hiSlice I.max := by simpa using hk
    rcases hwf with hlt | ⟨_, hlo⟩
    · rw [heq, BitVec.lt_def] at hlt; omega
    · exact ⟨BitVec.le_refl _, hlo⟩
  · simp only [hk, Bool.false_eq_true, ↓reduceIte]
    by_cases hmid : (hiSlice I.min).toNat + 1 < (hiSlice I.max).toNat
    · simp only [hmid, ↓reduceIte, List.mem_cons, List.not_mem_nil, or_false]
      rintro B (rfl | rfl | rfl)
      · exact ⟨BitVec.le_refl _, le_allOnes _⟩
      · refine ⟨?_, le_allOnes _⟩
        dsimp [UInterval.wf]
        rw [BitVec.le_def, BitVec.toNat_ofNat, BitVec.toNat_ofNat]
        have hmax := (hiSlice I.max).isLt
        have h1 : ((hiSlice I.min).toNat + 1) % 2 ^ w_hi = (hiSlice I.min).toNat + 1 :=
          Nat.mod_eq_of_lt (by omega)
        have h2 : ((hiSlice I.max).toNat - 1) % 2 ^ w_hi = (hiSlice I.max).toNat - 1 :=
          Nat.mod_eq_of_lt (by omega)
        omega
      · exact ⟨BitVec.le_refl _, zero_le_bv _⟩
    · simp only [hmid, ↓reduceIte, List.mem_cons, List.not_mem_nil, or_false]
      rintro B (rfl | rfl)
      · exact ⟨BitVec.le_refl _, le_allOnes _⟩
      · exact ⟨BitVec.le_refl _, zero_le_bv _⟩

/-- **Exactness of Subspace Projection (`projectInterval_spec`)**:
    For any `(w_lo, w_hi)` and any well-formed interval `I : UInterval (w_lo + w_hi)`,
    `x ∈ γ(I)` iff `x` belongs to one of the projected boxes `B ∈ projectInterval I`. -/
theorem projectInterval_spec {w_lo w_hi : Nat} (I : UInterval (w_lo + w_hi))
    (x : BitVec (w_lo + w_hi)) (hwf : I.wf) :
    (∃ B ∈ projectInterval I, gammaBox B x) ↔ gammaU I x := by
  dsimp [projectInterval, gammaU, UInterval.wf] at hwf ⊢
  rw [word_le_iff] at hwf
  rw [word_le_iff I.min x, word_le_iff x I.max]
  by_cases hk : (hiSlice I.min == hiSlice I.max) = true
  · simp only [hk, ↓reduceIte, List.mem_singleton, exists_eq_left, gammaBox, gammaU]
    have heq : hiSlice I.min = hiSlice I.max := by simpa using hk
    rw [heq]
    simp only [BitVec.lt_def, BitVec.le_def, ← BitVec.toNat_inj]
    omega
  · simp only [hk, Bool.false_eq_true, ↓reduceIte]
    have hne : hiSlice I.min ≠ hiSlice I.max := by
      intro h; apply hk; simpa using h
    have hlt_k : (hiSlice I.min).toNat < (hiSlice I.max).toNat := by
      rcases hwf with hlt | ⟨heq, _⟩
      · exact BitVec.lt_def.mp hlt
      · exact absurd heq hne
    by_cases hmid : (hiSlice I.min).toNat + 1 < (hiSlice I.max).toNat
    · simp only [hmid, ↓reduceIte, List.mem_cons, List.not_mem_nil, or_false,
                 exists_eq_or_imp, exists_eq_left, gammaBox, gammaU]
      have h_all : loSlice x ≤ BitVec.allOnes w_lo := le_allOnes (loSlice x)
      have h_zero : 0#w_lo ≤ loSlice x := zero_le_bv (loSlice x)
      have hmax_lt := (hiSlice I.max).isLt
      have h_ofNat1 : (BitVec.ofNat w_hi ((hiSlice I.min).toNat + 1)).toNat =
          (hiSlice I.min).toNat + 1 := by
        rw [BitVec.toNat_ofNat]
        exact Nat.mod_eq_of_lt (by omega)
      have h_ofNat2 : (BitVec.ofNat w_hi ((hiSlice I.max).toNat - 1)).toNat =
          (hiSlice I.max).toNat - 1 := by
        rw [BitVec.toNat_ofNat]
        exact Nat.mod_eq_of_lt (by omega)
      simp only [h_all, h_zero, and_true, true_and,
                 BitVec.lt_def, BitVec.le_def, ← BitVec.toNat_inj, h_ofNat1, h_ofNat2]
      omega
    · simp only [hmid, ↓reduceIte, List.mem_cons, List.not_mem_nil, or_false,
                 exists_eq_or_imp, exists_eq_left, gammaBox, gammaU]
      have h_all : loSlice x ≤ BitVec.allOnes w_lo := le_allOnes (loSlice x)
      have h_zero : 0#w_lo ≤ loSlice x := zero_le_bv (loSlice x)
      simp only [h_all, h_zero, and_true, true_and,
                 BitVec.lt_def, BitVec.le_def, ← BitVec.toNat_inj]
      omega

/-! ### §6.2 Stage 1: Signed-to-Unsigned Decomposition & Same-Width Intersection -/

/-- Exact intersection of two `w`-bit unsigned intervals:
    `[max(a.min, b.min), min(a.max, b.max)]` if non-empty. -/
def intersectU {w : Nat} (a b : UInterval w) : Option (UInterval w) :=
  let lo := if a.min ≤ b.min then b.min else a.min
  let hi := if a.max ≤ b.max then a.max else b.max
  if lo ≤ hi then some ⟨lo, hi⟩ else none

theorem intersectU_wf {w : Nat} (a b : UInterval w) :
    ∀ I, intersectU a b = some I → I.wf := by
  intro I h
  unfold intersectU at h
  by_cases hle : (if a.min ≤ b.min then b.min else a.min) ≤ (if a.max ≤ b.max then a.max else b.max)
  · simp only [hle, ↓reduceIte, Option.some.injEq] at h
    subst h
    exact hle
  · simp only [hle, ↓reduceIte, reduceCtorEq] at h

theorem intersectU_spec {w : Nat} (a b : UInterval w) (x : BitVec w) :
    (∃ I, intersectU a b = some I ∧ gammaU I x) ↔ (gammaU a x ∧ gammaU b x) := by
  dsimp [intersectU, gammaU]
  constructor
  · rintro ⟨I, hI, hx1, hx2⟩
    by_cases h1 : a.min ≤ b.min <;> by_cases h2 : a.max ≤ b.max <;>
      simp only [h1, h2, ↓reduceIte] at hI
    · split at hI
      · injection hI with hI; subst hI; simp only [BitVec.le_def] at *; omega
      · contradiction
    · split at hI
      · injection hI with hI; subst hI; simp only [BitVec.le_def] at *; omega
      · contradiction
    · split at hI
      · injection hI with hI; subst hI; simp only [BitVec.le_def] at *; omega
      · contradiction
    · split at hI
      · injection hI with hI; subst hI; simp only [BitVec.le_def] at *; omega
      · contradiction
  · rintro ⟨⟨ha1, ha2⟩, ⟨hb1, hb2⟩⟩
    by_cases h1 : a.min ≤ b.min <;> by_cases h2 : a.max ≤ b.max <;>
      simp only [h1, h2, ↓reduceIte]
    · have h3 : b.min ≤ a.max := by simp only [BitVec.le_def] at *; omega
      exact ⟨⟨b.min, a.max⟩, by simp [h3], hb1, ha2⟩
    · have h3 : b.min ≤ b.max := by simp only [BitVec.le_def] at *; omega
      exact ⟨⟨b.min, b.max⟩, by simp [h3], hb1, hb2⟩
    · have h3 : a.min ≤ a.max := by simp only [BitVec.le_def] at *; omega
      exact ⟨⟨a.min, a.max⟩, by simp [h3], ha1, ha2⟩
    · have h3 : a.min ≤ b.max := by simp only [BitVec.le_def] at *; omega
      exact ⟨⟨a.min, b.max⟩, by simp [h3], ha1, hb2⟩

/-- Split a `w`-bit signed interval into at most 2 unsigned intervals (Equation 20),
    intersecting each with `u : UInterval w` (Equations 23–24). -/
def stage1_width {w : Nat} (u : UInterval w) (s : SInterval w) : List (UInterval w) :=
  let parts : List (UInterval w) :=
    if s.crossesZero then
      [⟨0#w, s.smax⟩, ⟨s.smin, BitVec.allOnes w⟩]
    else
      [⟨s.smin, s.smax⟩]
  parts.filterMap (intersectU u)

/-- **Equation (23)**: Stage 1 on the full `(w_lo + w_hi)`-bit register (`U_64`, `|U_64| ≤ 2`). -/
def stage1_full {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : List (UInterval (w_lo + w_hi)) :=
  stage1_width r.u64 r.s64

/-- **Equation (24)**: Stage 1 on the lower `w_lo`-bit subregister (`U_32`, `|U_32| ≤ 2`). -/
def stage1_sub {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : List (UInterval w_lo) :=
  stage1_width r.u32 r.s32

theorem stage1_width_length_le_two {w : Nat} (u : UInterval w) (s : SInterval w) :
    (stage1_width u s).length ≤ 2 := by
  dsimp [stage1_width]
  split
  · dsimp [List.filterMap]
    cases intersectU u ⟨0#w, s.smax⟩ <;>
    cases intersectU u ⟨s.smin, BitVec.allOnes w⟩ <;> simp
  · dsimp [List.filterMap]
    cases intersectU u ⟨s.smin, s.smax⟩ <;> simp

theorem stage1_width_wf {w : Nat} (u : UInterval w) (s : SInterval w) :
    ∀ I ∈ stage1_width u s, I.wf := by
  intro I hmem
  dsimp [stage1_width] at hmem
  rw [List.mem_filterMap] at hmem
  rcases hmem with ⟨p, _, hp⟩
  exact intersectU_wf u p I hp

theorem stage1_width_spec {w : Nat} (u : UInterval w) (s : SInterval w)
    (x : BitVec w) (hs : s.wf) :
    (∃ I ∈ stage1_width u s, gammaU I x) ↔ (gammaU u x ∧ gammaS s x) := by
  dsimp [stage1_width]
  by_cases hcz : s.crossesZero = true
  · simp only [hcz, ↓reduceIte, List.mem_filterMap, List.mem_cons, List.not_mem_nil, or_false]
    rw [gammaS_crossesZero_split s x hs hcz]
    constructor
    · rintro ⟨I, ⟨p, rfl | rfl, hp⟩, hxI⟩
      · have h := (intersectU_spec u ⟨0#w, s.smax⟩ x).mp ⟨I, hp, hxI⟩
        exact ⟨h.1, Or.inl h.2⟩
      · have h := (intersectU_spec u ⟨s.smin, BitVec.allOnes w⟩ x).mp ⟨I, hp, hxI⟩
        exact ⟨h.1, Or.inr h.2⟩
    · rintro ⟨hxu, hxs1 | hxs2⟩
      · obtain ⟨I, hp, hxI⟩ := (intersectU_spec u ⟨0#w, s.smax⟩ x).mpr ⟨hxu, hxs1⟩
        exact ⟨I, ⟨⟨0#w, s.smax⟩, Or.inl rfl, hp⟩, hxI⟩
      · obtain ⟨I, hp, hxI⟩ := (intersectU_spec u ⟨s.smin, BitVec.allOnes w⟩ x).mpr ⟨hxu, hxs2⟩
        exact ⟨I, ⟨⟨s.smin, BitVec.allOnes w⟩, Or.inr rfl, hp⟩, hxI⟩
  · have hcz_f : s.crossesZero = false := by simpa using hcz
    simp only [hcz_f, Bool.false_eq_true, ↓reduceIte, List.mem_filterMap,
               List.mem_singleton, exists_eq_left]
    rw [gammaS_not_crossesZero s x hs hcz_f]
    exact intersectU_spec u ⟨s.smin, s.smax⟩ x

/-! ### §6.2 Stage 2: Subspace Projection & Cross-Width Narrowing (Equations 25–26) -/

/-- **Equation (25)**: Project each interval in `stage1_full r` into subspace boxes (`|P| ≤ 6`). -/
def stage2_project {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : List (SubspaceBox w_lo w_hi) :=
  (stage1_full r).flatMap projectInterval

/-- Narrow a `SubspaceBox w_lo w_hi` against a lower `w_lo`-bit interval `J ∈ U_32`. -/
def narrowBoxWithSub {w_lo w_hi : Nat} (B : SubspaceBox w_lo w_hi)
    (J : UInterval w_lo) : Option (SubspaceBox w_lo w_hi) :=
  match intersectU B.subRange J with
  | some sub' => some ⟨B.kRange, sub'⟩
  | none      => none

/-- **Equation (26)**: Pairwise narrow all projected boxes in `P` against `U_32` (`|W| ≤ 12`). -/
def stage2_narrow {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : List (SubspaceBox w_lo w_hi) :=
  (stage2_project r).flatMap (fun B => (stage1_sub r).filterMap (narrowBoxWithSub B))

theorem stage2_narrow_wf {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    ∀ B ∈ stage2_narrow r, B.wf := by
  intro B hmem
  dsimp [stage2_narrow, stage2_project, stage1_full, stage1_sub] at hmem
  rw [List.mem_flatMap] at hmem
  rcases hmem with ⟨B0, hB0, hmem2⟩
  rw [List.mem_flatMap] at hB0
  rcases hB0 with ⟨I64, hI64, hB0_proj⟩
  have hI64_wf := stage1_width_wf r.u64 r.s64 I64 hI64
  have hB0_wf := projectInterval_wf I64 hI64_wf B0 hB0_proj
  rw [List.mem_filterMap] at hmem2
  rcases hmem2 with ⟨J32, _, hnarrow⟩
  dsimp [narrowBoxWithSub] at hnarrow
  cases h_int : intersectU B0.subRange J32 with
  | none => rw [h_int] at hnarrow; contradiction
  | some sub' =>
    rw [h_int] at hnarrow
    injection hnarrow with hB; subst hB
    exact ⟨hB0_wf.1, intersectU_wf B0.subRange J32 sub' h_int⟩

/-- **Exactness of Stages 1 & 2 (`stage2_narrow_spec`)**:
    For any `(w_lo, w_hi)` and any `r : RegState w_lo w_hi` with well-formed signed bounds,
    `x` belongs to some narrowed box `B ∈ stage2_narrow r` iff `x` satisfies all four
    interval domains (`u64`, `s64`, `u32`, `s32`). -/
theorem stage2_narrow_spec {w_lo w_hi : Nat} (r : RegState w_lo w_hi)
    (x : BitVec (w_lo + w_hi)) (hs64 : r.s64.wf) (hs32 : r.s32.wf) :
    (∃ B ∈ stage2_narrow r, gammaBox B x) ↔
      (gammaU r.u64 x ∧ gammaS r.s64 x ∧ gammaUSub r.u32 x ∧ gammaSSub r.s32 x) := by
  dsimp [stage2_narrow, stage2_project, stage1_full, stage1_sub, gammaUSub, gammaSSub]
  have h_assoc : (gammaU r.u64 x ∧ gammaS r.s64 x ∧ gammaU r.u32 (loSlice x) ∧ gammaS r.s32 (loSlice x)) ↔
      ((gammaU r.u64 x ∧ gammaS r.s64 x) ∧ (gammaU r.u32 (loSlice x) ∧ gammaS r.s32 (loSlice x))) :=
    ⟨fun ⟨h1, h2, h3, h4⟩ => ⟨⟨h1, h2⟩, ⟨h3, h4⟩⟩, fun ⟨⟨h1, h2⟩, ⟨h3, h4⟩⟩ => ⟨h1, h2, h3, h4⟩⟩
  rw [h_assoc, ← stage1_width_spec r.u64 r.s64 x hs64, ← stage1_width_spec r.u32 r.s32 (loSlice x) hs32]
  constructor
  · rintro ⟨B, hB_mem, hxB⟩
    rw [List.mem_flatMap] at hB_mem
    rcases hB_mem with ⟨B0, hB0_mem, hB_filt⟩
    rw [List.mem_flatMap] at hB0_mem
    rcases hB0_mem with ⟨I64, hI64_mem, hB0_proj⟩
    rw [List.mem_filterMap] at hB_filt
    rcases hB_filt with ⟨J32, hJ32_mem, hnarrow⟩
    dsimp [narrowBoxWithSub] at hnarrow
    cases h_int : intersectU B0.subRange J32 with
    | none => rw [h_int] at hnarrow; contradiction
    | some sub' =>
      rw [h_int] at hnarrow
      injection hnarrow with hB; subst hB
      rcases hxB with ⟨hx_k, hx_sub'⟩
      have h_both := (intersectU_spec B0.subRange J32 (loSlice x)).mp ⟨sub', h_int, hx_sub'⟩
      have hI64_wf := stage1_width_wf r.u64 r.s64 I64 hI64_mem
      have hx_I64 := (projectInterval_spec I64 x hI64_wf).mp ⟨B0, hB0_proj, ⟨hx_k, h_both.1⟩⟩
      exact ⟨⟨I64, hI64_mem, hx_I64⟩, ⟨J32, hJ32_mem, h_both.2⟩⟩
  · rintro ⟨⟨I64, hI64_mem, hx_I64⟩, ⟨J32, hJ32_mem, hx_J32⟩⟩
    have hI64_wf := stage1_width_wf r.u64 r.s64 I64 hI64_mem
    obtain ⟨B0, hB0_proj, ⟨hx_k, hx_B0_sub⟩⟩ :=
      (projectInterval_spec I64 x hI64_wf).mpr hx_I64
    obtain ⟨sub', h_int, hx_sub'⟩ :=
      (intersectU_spec B0.subRange J32 (loSlice x)).mpr ⟨hx_B0_sub, hx_J32⟩
    refine ⟨⟨B0.kRange, sub'⟩, ?_, ⟨hx_k, hx_sub'⟩⟩
    rw [List.mem_flatMap]
    refine ⟨B0, ?_, ?_⟩
    · rw [List.mem_flatMap]
      exact ⟨I64, hI64_mem, hB0_proj⟩
    · rw [List.mem_filterMap]
      refine ⟨J32, hJ32_mem, ?_⟩
      simp [narrowBoxWithSub, h_int]

/-! ### §6.2 Stage 3: Tnum Verification via `tnum_step` (Equations 27–28) -/

/-- **Equations (27) & (28)**: Exact O(1) intersection test between a `w`-bit tnum `t`
    and a `w`-bit unsigned interval `I = [L, R]` using `tnum_step`:
    `((I.min & ~t.m) == t.v) || (I.min < (t.v | t.m) && tnum_step t I.min ≤ I.max)`. -/
def tnumIntersectsInterval {w : Nat} (t : Tnum w) (I : UInterval w) : Bool :=
  ((I.min &&& ~~~t.m) == t.v) ||
  (decide (I.min < (t.v ||| t.m)) && decide (tnum_step t I.min ≤ I.max))

theorem tnumIntersectsInterval_spec {w : Nat} (t : Tnum w) (I : UInterval w)
    (ht : t.wf) (hI : I.wf) :
    tnumIntersectsInterval t I = true ↔ ∃ x : BitVec w, gammaU I x ∧ gammaTnum t x := by
  unfold tnumIntersectsInterval
  rw [tnum_one_step_interval_intersection t I ht hI]
  simp [gammaTnum, Bool.or_eq_true, Bool.and_eq_true, decide_eq_true_eq]

/-- Stage 3 verification of a single `SubspaceBox w_lo w_hi` against `t : Tnum (w_lo + w_hi)`
    (Check 1: prefix compatibility Eq. 27, Check 2: subregister intersection Eq. 28). -/
def checkBoxAgainstTnum {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi))
    (B : SubspaceBox w_lo w_hi) : Bool :=
  tnumIntersectsInterval (tnumHi t) B.kRange &&
  tnumIntersectsInterval (tnumLo t) B.subRange

theorem checkBoxAgainstTnum_spec {w_lo w_hi : Nat} (t : Tnum (w_lo + w_hi))
    (B : SubspaceBox w_lo w_hi) (ht : t.wf) (hB : B.wf) :
    checkBoxAgainstTnum t B = true ↔
      ∃ x : BitVec (w_lo + w_hi), gammaBox B x ∧ gammaTnum t x := by
  unfold checkBoxAgainstTnum
  rw [Bool.and_eq_true]
  obtain ⟨ht_hi, ht_lo⟩ := (tnum_wf_split_iff t).mp ht
  rw [tnumIntersectsInterval_spec (tnumHi t) B.kRange ht_hi hB.1]
  rw [tnumIntersectsInterval_spec (tnumLo t) B.subRange ht_lo hB.2]
  constructor
  · rintro ⟨⟨k, hk_range, hk_tnum⟩, ⟨lo, hlo_range, hlo_tnum⟩⟩
    refine ⟨mkWord k lo, ?_, ?_⟩
    · unfold gammaBox
      rw [hiSlice_mkWord, loSlice_mkWord]
      exact ⟨hk_range, hlo_range⟩
    · rw [gammaTnum_split_iff, hiSlice_mkWord, loSlice_mkWord]
      exact ⟨hk_tnum, hlo_tnum⟩
  · rintro ⟨x, ⟨hx_k, hx_lo⟩, hx_tnum⟩
    obtain ⟨hx_thi, hx_tlo⟩ := (gammaTnum_split_iff t x).mp hx_tnum
    exact ⟨⟨hiSlice x, hx_k, hx_thi⟩, ⟨loSlice x, hx_lo, hx_tlo⟩⟩

/-- **The Complete Parametric 3-Stage Allwise Intersection Algorithm (`reg_bounds_intersect`)**:
    First checks `WF r`, then runs Stages 1, 2, and 3 to decide whether `γ_P(r) ≠ ∅`. -/
def reg_bounds_intersect {w_lo w_hi : Nat} (r : RegState w_lo w_hi) : Bool :=
  decide (WF r) && (stage2_narrow r).any (checkBoxAgainstTnum r.tnum)

/-- **Main Theorem (§6.2): Soundness and Completeness of `reg_bounds_intersect`**
    proved for **arbitrary bitwidths `w_lo, w_hi : Nat`**:
    `reg_bounds_intersect r = true` if and only if there exists a `(w_lo + w_hi)`-bit
    word `x` simultaneously satisfying all five abstract domains (`u64`, `s64`, `u32`, `s32`, `tnum`). -/
theorem reg_bounds_intersect_sound_and_complete {w_lo w_hi : Nat}
    (r : RegState w_lo w_hi) :
    reg_bounds_intersect r = true ↔ ∃ x : BitVec (w_lo + w_hi), gammaReg r x := by
  unfold reg_bounds_intersect
  rw [Bool.and_eq_true, decide_eq_true_eq, List.any_eq_true]
  constructor
  · rintro ⟨hwf, ⟨B, hB_mem, hB_check⟩⟩
    have hB_wf := stage2_narrow_wf r B hB_mem
    obtain ⟨x, hx_box, hx_tnum⟩ :=
      (checkBoxAgainstTnum_spec r.tnum B hwf.2.2.2.2 hB_wf).mp hB_check
    obtain ⟨hu64, hs64, hu32, hs32⟩ :=
      (stage2_narrow_spec r x hwf.2.1 hwf.2.2.2.1).mp ⟨B, hB_mem, hx_box⟩
    exact ⟨x, hu64, hs64, hu32, hs32, hx_tnum⟩
  · rintro ⟨x, hx⟩
    have hcm : CM r := mem_gammaReg_implies_cm r x hx
    have hwf : WF r := hcm.1
    rcases hx with ⟨hu64, hs64, hu32, hs32, hx_tnum⟩
    obtain ⟨B, hB_mem, hx_box⟩ :=
      (stage2_narrow_spec r x hwf.2.1 hwf.2.2.2.1).mpr ⟨hu64, hs64, hu32, hs32⟩
    have hB_wf := stage2_narrow_wf r B hB_mem
    have hB_check :=
      (checkBoxAgainstTnum_spec r.tnum B hwf.2.2.2.2 hB_wf).mpr ⟨x, hx_box, hx_tnum⟩
    exact ⟨hwf, ⟨B, hB_mem, hB_check⟩⟩

/-- **Corollary 1**: `reg_bounds_intersect r = true` iff `r ∈ CM` (Cohesive-Measured). -/
theorem reg_bounds_intersect_iff_cm {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    reg_bounds_intersect r = true ↔ CM r := by
  rw [reg_bounds_intersect_sound_and_complete]
  constructor
  · rintro ⟨x, hx⟩
    exact mem_gammaReg_implies_cm r x hx
  · rintro ⟨_, hx⟩
    exact hx

/-- **Corollary 2**: `reg_bounds_intersect r = false` iff `r ∈ EI ∪ IF_state`. -/
theorem reg_bounds_intersect_false_iff_ei_or_if {w_lo w_hi : Nat} (r : RegState w_lo w_hi) :
    reg_bounds_intersect r = false ↔ (EI r ∨ IF_state r) := by
  rw [← Bool.not_eq_true, reg_bounds_intersect_iff_cm]
  constructor
  · intro hnot_cm
    rcases universe_partition_trichotomy r with hcm | hei | hif
    · exact absurd hcm hnot_cm
    · exact Or.inl hei
    · exact Or.inr hif
  · rintro (hei | hif) hcm
    · exact cm_and_ei_disjoint r ⟨hcm, hei⟩
    · exact wf_and_if_disjoint r ⟨hcm.1, hif⟩

/-! ### §6.2 Walkthrough Examples (Figures 5 & 6, Instantiated at `w_lo = 32, w_hi = 32`) -/

/-- **Figure 5(a) Walkthrough**: Spanning prefix `[2^32, 3*2^32 - 1]` with `tnumHi = (0, 2)`
    (requiring bit 32 = 0, so `k` must be even). `k = 1` fails Check 1, while `k = 2` passes! -/
theorem fig5a_prefix_walkthrough :
    let t_hi : Tnum 32 := ⟨0#32, 2#32⟩
    tnumIntersectsInterval t_hi ⟨1#32, 1#32⟩ = false ∧
    tnumIntersectsInterval t_hi ⟨2#32, 2#32⟩ = true := by
  decide

/-- **Figure 5(b) Walkthrough**: Subregister interval `[2, 3]` vs `tnumLo = (0, 4)` (`{0, 4}`).
    `tnum_step (0, 4) 2 = 4 > 3`, detecting emptiness (`false`). -/
theorem fig5b_subregister_walkthrough :
    let t_lo : Tnum 32 := ⟨0#32, 4#32⟩
    tnum_step t_lo 2#32 = 4#32 ∧
    tnumIntersectsInterval t_lo ⟨2#32, 3#32⟩ = false := by
  decide

/-- **Figure 6, Example 1 (Cross-Width Contradiction, `EI` State)**:
    `u64 = [2^32 + 5, 2*2^32 + 3]`, `s64 = [2^32 + 5, 2*2^32 + 3]`,
    `u32 = [2, 3]`, `s32 = [2, 3]`, `tnum = (0, (2 << 32) | 4)`.
    All five domains are individually well-formed (`WF`), yet `reg_bounds_intersect`
    returns `false` (`EI`) because `k = 1` fails `tnumHi` and `k = 2` has `[2, 3] ∩ {0, 4} = ∅`. -/
def fig6_example1_state : RegState 32 32 where
  u64  := ⟨0x0000000100000005#64, 0x0000000200000003#64⟩
  s64  := ⟨0x0000000100000005#64, 0x0000000200000003#64⟩
  u32  := ⟨2#32, 3#32⟩
  s32  := ⟨2#32, 3#32⟩
  tnum := ⟨0#64, 0x0000000200000004#64⟩

theorem fig6_example1_verified :
    WF fig6_example1_state ∧
    reg_bounds_intersect fig6_example1_state = false ∧
    EI fig6_example1_state := by
  have hwf : WF fig6_example1_state := by decide
  have hfalse : reg_bounds_intersect fig6_example1_state = false := by decide
  have hei_or_if := (reg_bounds_intersect_false_iff_ei_or_if fig6_example1_state).mp hfalse
  rcases hei_or_if with hei | hif
  · exact ⟨hwf, hfalse, hei⟩
  · exact absurd hwf hif

/-- **Figure 6, Example 2 (Satisfiable Intersection, `CM` State)**:
    Changing `u32` and `s32` to `[2, 5]` allows `tnum_step (0, 4) 2 = 4 ≤ 5` in subspace `k = 2`,
    yielding concrete witness `x = 2*2^32 + 4 = 0x0000000200000004` (`reg_bounds_intersect = true`). -/
def fig6_example2_state : RegState 32 32 where
  u64  := ⟨0x0000000100000005#64, 0x0000000200000008#64⟩
  s64  := ⟨0x0000000100000005#64, 0x0000000200000008#64⟩
  u32  := ⟨2#32, 5#32⟩
  s32  := ⟨2#32, 5#32⟩
  tnum := ⟨0#64, 0x0000000200000004#64⟩

theorem fig6_example2_verified :
    reg_bounds_intersect fig6_example2_state = true ∧
    gammaReg fig6_example2_state 0x0000000200000004#64 ∧
    CM fig6_example2_state := by
  have htrue : reg_bounds_intersect fig6_example2_state = true := by decide
  have hmem : gammaReg fig6_example2_state 0x0000000200000004#64 := by decide
  exact ⟨htrue, hmem, (reg_bounds_intersect_iff_cm fig6_example2_state).mp htrue⟩

/-!
================================================================================
## §6.3 Dead Branch Pruning via `simulate_both_branches_taken`
================================================================================
Finally, we formalize the integration of `reg_bounds_intersect` into
`is_branch_taken()` via `simulate_both_branches_taken()` (§6.3) and prove that
pruning any branch where `reg_bounds_intersect` returns `false` on a refined
scratch register is **100% sound** for all bitwidths `w_lo, w_hi : Nat`.
-/

/-- Return code of `is_branch_taken` / `simulate_both_branches_taken` (§6.3). -/
inductive BranchResolution where
  | takenOnly       -- Return `1`: False (fall-through) branch is provably dead
  | fallthroughOnly -- Return `0`: True (jump target) branch is provably dead
  | bothFeasible    -- Return `-1`: Both branches have non-empty 5-domain intersections
  | unreachableNode -- Both branches are dead (current program point is unreachable)
  deriving DecidableEq, Repr

/-- **§6.3 `simulate_both_branches_taken`**:
    Refines scratch copies `(r1_t, r2_t) ← refineTrue r1 r2` and `(r1_f, r2_f) ← refineFalse r1 r2`
    prior to any state forking or `reg_bounds_sync`, and invokes `reg_bounds_intersect`
    to prune infeasible branches. -/
def simulate_both_branches_taken {w_lo w_hi : Nat}
    (refineTrue refineFalse :
      RegState w_lo w_hi → RegState w_lo w_hi → RegState w_lo w_hi × RegState w_lo w_hi)
    (r1 r2 : RegState w_lo w_hi) : BranchResolution :=
  let (r1_t, r2_t) := refineTrue r1 r2
  let (r1_f, r2_f) := refineFalse r1 r2
  let true_feasible  := reg_bounds_intersect r1_t && reg_bounds_intersect r2_t
  let false_feasible := reg_bounds_intersect r1_f && reg_bounds_intersect r2_f
  match true_feasible, false_feasible with
  | true,  false => .takenOnly
  | false, true  => .fallthroughOnly
  | true,  true  => .bothFeasible
  | false, false => .unreachableNode

/-- **Soundness of Dead Branch Pruning (`simulate_both_branches_taken_sound`)**:
    For any bitwidths `w_lo, w_hi : Nat` and any sound conditional jump refinement
    operators `refineTrue, refineFalse` (satisfying Equation 9):
    1. If `simulate_both_branches_taken` returns `.takenOnly`, no concrete `(x, y) ∈ γ_P(r1) × γ_P(r2)`
       can take the fall-through branch (`∀ x y, ¬cond x y` is impossible, i.e., `cond x y` always holds).
    2. If `simulate_both_branches_taken` returns `.fallthroughOnly`, no concrete `(x, y) ∈ γ_P(r1) × γ_P(r2)`
       can take the jump target branch (`¬cond x y` always holds).
    3. Every feasible concrete execution is preserved in `CM` states without ever invoking
       `reg_bounds_sync` on an `EI` state. -/
theorem simulate_both_branches_taken_sound {w_lo w_hi : Nat}
    (cond : BitVec (w_lo + w_hi) → BitVec (w_lo + w_hi) → Prop)
    (refineTrue refineFalse :
      RegState w_lo w_hi → RegState w_lo w_hi → RegState w_lo w_hi × RegState w_lo w_hi)
    (h_sound : JumpRefineSound cond refineTrue refineFalse)
    (r1 r2 : RegState w_lo w_hi) :
    (simulate_both_branches_taken refineTrue refineFalse r1 r2 = .takenOnly →
      ∀ x y, gammaReg r1 x → gammaReg r2 y → cond x y) ∧
    (simulate_both_branches_taken refineTrue refineFalse r1 r2 = .fallthroughOnly →
      ∀ x y, gammaReg r1 x → gammaReg r2 y → ¬cond x y) := by
  dsimp [simulate_both_branches_taken]
  generalize h_tf : (reg_bounds_intersect (refineTrue r1 r2).1 &&
                     reg_bounds_intersect (refineTrue r1 r2).2) = tf
  generalize h_ff : (reg_bounds_intersect (refineFalse r1 r2).1 &&
                     reg_bounds_intersect (refineFalse r1 r2).2) = ff
  constructor
  · intro hres x y hx hy
    apply Classical.byContradiction
    intro hnot_cond
    have ⟨hx_f, hy_f⟩ := (h_sound r1 r2 x y hx hy).2 hnot_cond
    have h1 : reg_bounds_intersect (refineFalse r1 r2).1 = true :=
      (reg_bounds_intersect_sound_and_complete _).mpr ⟨x, hx_f⟩
    have h2 : reg_bounds_intersect (refineFalse r1 r2).2 = true :=
      (reg_bounds_intersect_sound_and_complete _).mpr ⟨y, hy_f⟩
    rw [h1, h2] at h_ff
    cases tf <;> cases ff <;> contradiction
  · intro hres x y hx hy hcond
    have ⟨hx_t, hy_t⟩ := (h_sound r1 r2 x y hx hy).1 hcond
    have h1 : reg_bounds_intersect (refineTrue r1 r2).1 = true :=
      (reg_bounds_intersect_sound_and_complete _).mpr ⟨x, hx_t⟩
    have h2 : reg_bounds_intersect (refineTrue r1 r2).2 = true :=
      (reg_bounds_intersect_sound_and_complete _).mpr ⟨y, hy_t⟩
    rw [h1, h2] at h_tf
    cases tf <;> cases ff <;> contradiction

end PLDIProofs
