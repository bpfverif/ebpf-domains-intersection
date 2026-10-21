import Std.Tactic.BVDecide

namespace TnumStep

/-- A 64-bit tristate number (`struct tnum` in the Linux kernel). -/
structure Tnum where
  value : BitVec 64
  mask  : BitVec 64
  deriving DecidableEq, Repr

/-- Well-formedness invariant for a `tnum`: known bits and unknown mask bits are disjoint. -/
def Tnum.wf (t : Tnum) : Prop :=
  (t.value &&& t.mask) = 0#64

/-- Membership in the concretization `γ(t)`: `x` agrees with `t.value` on all known bits. -/
def Tnum.mem (x : BitVec 64) (t : Tnum) : Prop :=
  (x &&& ~~~t.mask) = t.value

/-- Computable boolean membership check (`tnum_in(t, TNUM(x, 0))` in the Linux kernel). -/
def Tnum.memB (x : BitVec 64) (t : Tnum) : Bool :=
  (x &&& ~~~t.mask) == t.value

/-- `Tnum.memB` reflects `Tnum.mem`. -/
theorem Tnum.memB_iff (x : BitVec 64) (t : Tnum) :
    Tnum.memB x t = true ↔ Tnum.mem x t := by
  unfold Tnum.memB Tnum.mem
  bv_decide

/-- Maximum 64-bit unsigned integer (`U64_MAX`). -/
abbrev U64_MAX : BitVec 64 := ~~~0#64

/-- Upper 32-bit mask (`0xFFFF_FFFF_0000_0000`) used in 32-bit block decomposition. -/
abbrev UPPER_HALF : BitVec 64 := 0xFFFF_FFFF_0000_0000#64

/-- Lower 32-bit mask (`0x0000_0000_FFFF_FFFF`) used in 32-bit subregister projection. -/
abbrev LOWER_HALF : BitVec 64 := 0x0000_0000_FFFF_FFFF#64

/-- Linux kernel `fls64(x)`: 1-indexed position of the most-significant set bit (0 if `x = 0`). -/
def fls64 (x : BitVec 64) : BitVec 64 :=
  64#64 - x.clz

/-- Faithful translation of the Linux kernel C function `u64 tnum_step(struct tnum t, u64 z)`. -/
def tnum_step (t : Tnum) (z : BitVec 64) : BitVec 64 :=
  let tmax := t.value ||| t.mask
  if z ≥ tmax then
    tmax
  else if z < t.value then
    t.value
  else
    let j := t.value ||| (z &&& t.mask)
    if j > z then
      let p := ~~~z &&& t.value &&& ~~~t.mask
      let k := fls64 p
      let q := U64_MAX <<< k
      let r := q &&& z
      let s := ~~~q &&& t.value
      let v := r ||| s
      let res := v
      res
    else
      let p := z &&& ~~~t.value &&& ~~~t.mask
      let k := fls64 p
      let q := U64_MAX <<< k
      let r := q &&& t.mask &&& z
      let s := q &&& ~~~t.mask
      let v := r ||| s
      let u := v + (1#64 <<< k)
      let w := (u &&& t.mask) ||| t.value
      let res := w
      res

/-! ## Basic Properties of `Tnum` Concretization -/

/-- The smallest member of a well-formed `tnum` is `t.value`. -/
theorem Tnum.mem_value (t : Tnum) (hwf : t.wf) : Tnum.mem t.value t := by
  unfold Tnum.wf Tnum.mem at *
  bv_decide

/-- The largest member of a well-formed `tnum` is `t.value ||| t.mask`. -/
theorem Tnum.mem_tmax (t : Tnum) (hwf : t.wf) : Tnum.mem (t.value ||| t.mask) t := by
  unfold Tnum.wf Tnum.mem at *
  bv_decide

/-- Every member `x` of `t` lies in `[t.value, t.value ||| t.mask]`. -/
theorem Tnum.mem_bounds (t : Tnum) (x : BitVec 64) (hx : Tnum.mem x t) :
    t.value ≤ x ∧ x ≤ (t.value ||| t.mask) := by
  unfold Tnum.mem at *
  bv_decide

/-! ## Boundary Behavior of `tnum_step` -/

/-- When `z ≥ tmax`, `tnum_step` returns `tmax = t.value ||| t.mask`. -/
theorem tnum_step_ge_tmax (t : Tnum) (z : BitVec 64)
    (hz : z ≥ (t.value ||| t.mask)) :
    tnum_step t z = (t.value ||| t.mask) := by
  unfold tnum_step
  bv_decide

/-- When `z < t.value` for a well-formed `tnum`, `tnum_step` returns `t.value`. -/
theorem tnum_step_lt_value (t : Tnum) (z : BitVec 64)
    (hwf : t.wf) (hz : z < t.value) :
    tnum_step t z = t.value := by
  unfold Tnum.wf tnum_step fls64 U64_MAX at *
  bv_decide

/-! ## Shift Safety (Absence of Shift Undefined Behavior in C) -/

/-- In the `j > z` branch (`t.value ≤ z < tmax`), the flip mask `p` is non-zero and `1 ≤ fls64 p ≤ 63`. -/
theorem tnum_step_shift_safe_gt (t : Tnum) (z : BitVec 64)
    (hwf : t.wf)
    (hmin : t.value ≤ z)
    (hmax : z < (t.value ||| t.mask))
    (hj : (t.value ||| (z &&& t.mask)) > z) :
    let p := ~~~z &&& t.value &&& ~~~t.mask
    let k := fls64 p
    p ≠ 0#64 ∧ 1#64 ≤ k ∧ k ≤ 63#64 := by
  unfold Tnum.wf fls64 at *
  bv_decide

/-- In the `j ≤ z` branch (`t.value ≤ z < tmax`), the shift amount `k = fls64 p` always satisfies `k ≤ 63`
(`k = 0` when `j = z` is already a member of `t`, and `1 ≤ k ≤ 63` when `j < z`). -/
theorem tnum_step_shift_safe_le (t : Tnum) (z : BitVec 64)
    (hwf : t.wf)
    (hmin : t.value ≤ z)
    (hmax : z < (t.value ||| t.mask))
    (hj : ¬((t.value ||| (z &&& t.mask)) > z)) :
    let p := z &&& ~~~t.value &&& ~~~t.mask
    let k := fls64 p
    k ≤ 63#64 ∧ ((t.value ||| (z &&& t.mask)) < z → p ≠ 0#64 ∧ 1#64 ≤ k) := by
  unfold Tnum.wf fls64 at *
  bv_decide

/-! ## Core Correctness Theorems for `tnum_step` -/

/-- **Membership**: For any well-formed `tnum`, `tnum_step t z` is a member of `t`. -/
theorem tnum_step_mem (t : Tnum) (z : BitVec 64) (hwf : t.wf) :
    Tnum.mem (tnum_step t z) t := by
  unfold Tnum.wf Tnum.mem tnum_step fls64 U64_MAX at *
  bv_decide

/-- **Bounds**: For any well-formed `tnum`, `t.value ≤ tnum_step t z ≤ (t.value ||| t.mask)`. -/
theorem tnum_step_bounds (t : Tnum) (z : BitVec 64) (hwf : t.wf) :
    t.value ≤ tnum_step t z ∧ tnum_step t z ≤ (t.value ||| t.mask) :=
  Tnum.mem_bounds t (tnum_step t z) (tnum_step_mem t z hwf)

/-- **Strict Progress**: Whenever `z` is strictly below `tmax`, `tnum_step t z` is strictly above `z`. -/
theorem tnum_step_gt (t : Tnum) (z : BitVec 64)
    (hwf : t.wf) (hz : z < (t.value ||| t.mask)) :
    z < tnum_step t z := by
  unfold Tnum.wf tnum_step fls64 U64_MAX at *
  bv_decide

/-- **Minimality (No Skipped Members)**: Any member `y` of `t` strictly greater than `z` is at least `tnum_step t z`. -/
theorem tnum_step_minimal (t : Tnum) (z y : BitVec 64)
    (hwf : t.wf) (hy : Tnum.mem y t) (hzy : z < y) :
    tnum_step t z ≤ y := by
  unfold Tnum.wf Tnum.mem tnum_step fls64 U64_MAX at *
  bv_decide

/-- **Complete Functional Specification of `tnum_step`**:
For every well-formed `t` and every `z : BitVec 64`:
1. `tnum_step t z` is in `γ(t)`,
2. `t.value ≤ tnum_step t z ≤ tmax`,
3. If `z ≥ tmax`, `tnum_step t z = tmax`,
4. If `z < t.value`, `tnum_step t z = t.value`,
5. If `z < tmax`, `z < tnum_step t z`, and
6. For every `y ∈ γ(t)` with `z < y`, `tnum_step t z ≤ y`. -/
theorem tnum_step_correct (t : Tnum) (z : BitVec 64) (hwf : t.wf) :
    Tnum.mem (tnum_step t z) t ∧
    (t.value ≤ tnum_step t z ∧ tnum_step t z ≤ (t.value ||| t.mask)) ∧
    (z ≥ (t.value ||| t.mask) → tnum_step t z = (t.value ||| t.mask)) ∧
    (z < t.value → tnum_step t z = t.value) ∧
    (z < (t.value ||| t.mask) → z < tnum_step t z) ∧
    (∀ y : BitVec 64, Tnum.mem y t → z < y → tnum_step t z ≤ y) :=
  ⟨tnum_step_mem t z hwf,
   tnum_step_bounds t z hwf,
   tnum_step_ge_tmax t z,
   tnum_step_lt_value t z hwf,
   tnum_step_gt t z hwf,
   fun y hy hzy => tnum_step_minimal t z y hwf hy hzy⟩

/-- **Uniqueness of the Least Upper Bound**:
When `z < tmax`, `tnum_step t z` is the unique element `x` that belongs to `γ(t)`,
is strictly greater than `z`, and is `≤` every `y ∈ γ(t)` with `z < y`. -/
theorem tnum_step_unique (t : Tnum) (z x : BitVec 64)
    (hwf : t.wf) (hz : z < (t.value ||| t.mask))
    (hx_mem : Tnum.mem x t) (hzx : z < x)
    (hx_min : ∀ y : BitVec 64, Tnum.mem y t → z < y → x ≤ y) :
    x = tnum_step t z := by
  have h1 : tnum_step t z ≤ x := tnum_step_minimal t z x hwf hx_mem hzx
  have h2 : x ≤ tnum_step t z := hx_min (tnum_step t z) (tnum_step_mem t z hwf) (tnum_step_gt t z hwf hz)
  exact BitVec.le_antisymm h2 h1

/-! ## Branch-Level Invariants and Intermediate Variable Properties -/

/-- A value `z` is already a member of a well-formed `tnum` `t` if and only if
matching unknown bits of `t` to `z` (`j = t.value | (z & t.mask)`) yields `z` itself. -/
theorem tnum_mem_iff_j_eq_z (t : Tnum) (z : BitVec 64) (hwf : t.wf) :
    Tnum.mem z t ↔ (t.value ||| (z &&& t.mask)) = z := by
  unfold Tnum.wf Tnum.mem at *
  bv_decide

/-- When `z ≥ tmax`, no member `y` of `t` is strictly greater than `z`. -/
theorem tnum_step_no_member_gt_of_ge_tmax (t : Tnum) (z y : BitVec 64)
    (hz : z ≥ (t.value ||| t.mask)) (hy : Tnum.mem y t) :
    ¬(z < y) := by
  unfold Tnum.mem at *
  bv_decide

/-- In the `j > z` branch (0-to-1 flip at `k = fls64 p`), matching positions `> k` to `z` (`r = q & z`)
already agrees with `t.value` on all known bits strictly above `k`. -/
theorem tnum_step_case_gt_high_bits_agree (t : Tnum) (z : BitVec 64)
    (hwf : t.wf)
    (hmin : t.value ≤ z)
    (hmax : z < (t.value ||| t.mask))
    (hj : (t.value ||| (z &&& t.mask)) > z) :
    let p := ~~~z &&& t.value &&& ~~~t.mask
    let k := fls64 p
    let q := U64_MAX <<< k
    let r := q &&& z
    (r &&& ~~~t.mask) = (q &&& t.value) := by
  unfold Tnum.wf fls64 U64_MAX at *
  bv_decide

/-- In the `j ≤ z` branch, setting known bits above `k` to `1` (`s = q & ~t.mask`) before adding `1ULL << k`
ensures that any carry propagates cleanly across known bit positions into the next unknown bit position. -/
theorem tnum_step_case_le_carry_correct (t : Tnum) (z : BitVec 64)
    (hwf : t.wf)
    (hmin : t.value ≤ z)
    (hmax : z < (t.value ||| t.mask))
    (hj : ¬((t.value ||| (z &&& t.mask)) > z)) :
    let p := z &&& ~~~t.value &&& ~~~t.mask
    let k := fls64 p
    let q := U64_MAX <<< k
    let r := q &&& t.mask &&& z
    let s := q &&& ~~~t.mask
    let v := r ||| s
    let u := v + (1#64 <<< k)
    let w := (u &&& t.mask) ||| t.value
    Tnum.mem w t ∧ z < w ∧ w = tnum_step t z := by
  unfold Tnum.wf Tnum.mem tnum_step fls64 U64_MAX at *
  bv_decide

/-! ## C `u8 k` Narrowing Equivalence and Simplified Branchless Formulation -/

/-- Variant of `tnum_step` modeling `u8 k = (u8)fls64(p)` as an 8-bit unsigned integer (`BitVec 8`). -/
def tnum_step_u8 (t : Tnum) (z : BitVec 64) : BitVec 64 :=
  let tmax := t.value ||| t.mask
  if z ≥ tmax then
    tmax
  else if z < t.value then
    t.value
  else
    let j := t.value ||| (z &&& t.mask)
    if j > z then
      let p := ~~~z &&& t.value &&& ~~~t.mask
      let k : BitVec 8 := (fls64 p).truncate 8
      let q := U64_MAX <<< k.zeroExtend 64
      let r := q &&& z
      let s := ~~~q &&& t.value
      let v := r ||| s
      v
    else
      let p := z &&& ~~~t.value &&& ~~~t.mask
      let k : BitVec 8 := (fls64 p).truncate 8
      let q := U64_MAX <<< k.zeroExtend 64
      let r := q &&& t.mask &&& z
      let s := q &&& ~~~t.mask
      let v := r ||| s
      let u := v + (1#64 <<< k.zeroExtend 64)
      let w := (u &&& t.mask) ||| t.value
      w

/-- Storing `k = fls64(p)` in a C `u8` (`BitVec 8`) preserves the exact result of `tnum_step`. -/
theorem tnum_step_u8_eq (t : Tnum) (z : BitVec 64) :
    tnum_step_u8 t z = tnum_step t z := by
  unfold tnum_step_u8 tnum_step fls64 U64_MAX
  bv_decide

/-- Branchless formulation of `tnum_step`. -/
def tnum_step_simplified (t : Tnum) (z : BitVec 64) : BitVec 64 :=
  let tmax := t.value ||| t.mask
  if z ≥ tmax then
    tmax
  else if z < t.value then
    t.value
  else
    let d := z - t.value
    let carry_mask := (1#64 <<< fls64 (d &&& ~~~t.mask)) - 1#64
    let filled := d ||| carry_mask ||| ~~~t.mask
    let inc := (filled + 1#64) &&& t.mask
    t.value ||| inc

/-- For every well-formed `tnum`, the two-branch `tnum_step` and `tnum_step_simplified` are identical. -/
theorem tnum_step_eq_simplified (t : Tnum) (z : BitVec 64) (hwf : t.wf) :
    tnum_step t z = tnum_step_simplified t z := by
  unfold Tnum.wf tnum_step tnum_step_simplified fls64 U64_MAX at *
  bv_decide

/-! ## Theorem 2: One-Step Range-Tnum Intersection via `tnum_step` -/

/-- There exists a member `y` of a well-formed `tnum` `t` in the half-open interval `(z, umax]`
if and only if `z < tmax` and `tnum_step t z ≤ umax`. -/
theorem tnum_step_exists_in_range_iff (t : Tnum) (z umax : BitVec 64) (hwf : t.wf) :
    (∃ y : BitVec 64, Tnum.mem y t ∧ z < y ∧ y ≤ umax) ↔
    (z < (t.value ||| t.mask) ∧ tnum_step t z ≤ umax) := by
  constructor
  · rintro ⟨y, hy_mem, hzy, hy_max⟩
    have hy_bounds : t.value ≤ y ∧ y ≤ (t.value ||| t.mask) := Tnum.mem_bounds t y hy_mem
    have hstep_le_y : tnum_step t z ≤ y := tnum_step_minimal t z y hwf hy_mem hzy
    exact ⟨by bv_decide, by bv_decide⟩
  · rintro ⟨hz_lt_tmax, hstep_le_umax⟩
    exact ⟨tnum_step t z, tnum_step_mem t z hwf, tnum_step_gt t z hwf hz_lt_tmax, hstep_le_umax⟩

/-- Returns the least member of `t` at or above `umin` (when `umin ≤ tmax`):
if `umin` is already in `γ(t)`, returns `umin`; otherwise steps once via `tnum_step t umin`. -/
def tnum_first_ge (t : Tnum) (umin : BitVec 64) : BitVec 64 :=
  if Tnum.memB umin t then umin else tnum_step t umin

/-- `tnum_first_ge t umin` is always a member of `γ(t)` for well-formed `t`. -/
theorem tnum_first_ge_mem (t : Tnum) (umin : BitVec 64) (hwf : t.wf) :
    Tnum.mem (tnum_first_ge t umin) t := by
  unfold tnum_first_ge Tnum.memB Tnum.wf Tnum.mem tnum_step fls64 U64_MAX at *
  bv_decide

/-- Whenever `umin ≤ tmax`, `tnum_first_ge t umin` is at least `umin`. -/
theorem tnum_first_ge_ge (t : Tnum) (umin : BitVec 64)
    (hwf : t.wf) (h : umin ≤ (t.value ||| t.mask)) :
    umin ≤ tnum_first_ge t umin := by
  unfold tnum_first_ge Tnum.memB Tnum.wf tnum_step fls64 U64_MAX at *
  bv_decide

/-- Every member `y ∈ γ(t)` with `umin ≤ y` is at least `tnum_first_ge t umin`. -/
theorem tnum_first_ge_minimal (t : Tnum) (umin y : BitVec 64)
    (hwf : t.wf) (hy : Tnum.mem y t) (hmin : umin ≤ y) :
    tnum_first_ge t umin ≤ y := by
  unfold tnum_first_ge Tnum.memB Tnum.wf Tnum.mem tnum_step fls64 U64_MAX at *
  bv_decide

/-- Unsigned 64-bit `u64`-`tnum` one-step intersection check (Theorem 2 / Equations 24 & 25):
```c
if (tmax < umin || tmin > umax)
    return false;
if (t.value != (umin & ~t.mask)) {
    if (tnum_step(t, umin) > umax)
        return false;
}
return true;
```
-/
def tnum_u64_intersect (t : Tnum) (umin umax : BitVec 64) : Bool :=
  let tmin := t.value
  let tmax := t.value ||| t.mask
  if tmax < umin || tmin > umax then
    false
  else if t.value != (umin &&& ~~~t.mask) then
    if tnum_step t umin > umax then
      false
    else
      true
  else
    true

/-- **Soundness of `tnum_u64_intersect` (Witness Existence)**:
Whenever `t` is well-formed, `umin ≤ umax`, and `tnum_u64_intersect t umin umax = true`,
`tnum_first_ge t umin` is a valid member of `t` inside `[umin, umax]`. -/
theorem tnum_u64_intersect_sound (t : Tnum) (umin umax : BitVec 64)
    (hwf : t.wf) (hrange : umin ≤ umax)
    (h : tnum_u64_intersect t umin umax = true) :
    ∃ x : BitVec 64, Tnum.mem x t ∧ umin ≤ x ∧ x ≤ umax := by
  refine ⟨tnum_first_ge t umin, tnum_first_ge_mem t umin hwf, ?_, ?_⟩
  · unfold tnum_first_ge Tnum.memB Tnum.wf tnum_u64_intersect tnum_step fls64 U64_MAX at *
    bv_decide
  · unfold tnum_first_ge Tnum.memB Tnum.wf tnum_u64_intersect tnum_step fls64 U64_MAX at *
    bv_decide

/-- **Completeness of `tnum_u64_intersect`**:
Whenever there exists a member `x ∈ γ(t)` with `umin ≤ x ≤ umax`,
`tnum_u64_intersect t umin umax` returns `true`. -/
theorem tnum_u64_intersect_complete (t : Tnum) (umin umax x : BitVec 64)
    (hwf : t.wf) (hx : Tnum.mem x t) (hmin : umin ≤ x) (hmax : x ≤ umax) :
    tnum_u64_intersect t umin umax = true := by
  unfold Tnum.wf Tnum.mem tnum_u64_intersect tnum_step fls64 U64_MAX at *
  bv_decide

/-- **Exact Characterization of `tnum_u64_intersect` (Theorem 2)**:
For any well-formed `t` and valid unsigned range `umin ≤ umax`,
`tnum_u64_intersect t umin umax = true` if and only if `γ(t) ∩ [umin, umax]` is non-empty. -/
theorem tnum_u64_intersect_iff (t : Tnum) (umin umax : BitVec 64)
    (hwf : t.wf) (hrange : umin ≤ umax) :
    tnum_u64_intersect t umin umax = true ↔
    (∃ x : BitVec 64, Tnum.mem x t ∧ umin ≤ x ∧ x ≤ umax) :=
  ⟨tnum_u64_intersect_sound t umin umax hwf hrange,
   fun ⟨x, hx, hmin, hmax⟩ => tnum_u64_intersect_complete t umin umax x hwf hx hmin hmax⟩

/-- Equivalence with the paper's Equation (25) formula `(a ∈ γ(t)) ∨ (tnum_step(t, a) ≤ b)`
whenever `a ≤ b` and `a ≤ tmax`. -/
theorem tnum_u64_intersect_eq_paper_formula (t : Tnum) (a b : BitVec 64)
    (hwf : t.wf) (hab : a ≤ b) (hmax : a ≤ (t.value ||| t.mask)) :
    tnum_u64_intersect t a b = (Tnum.memB a t || decide (tnum_step t a ≤ b)) := by
  unfold tnum_u64_intersect Tnum.memB Tnum.wf tnum_step fls64 U64_MAX at *
  bv_decide

/-! ## Section 6.1: eBPF Domains, Discontinuities, and 32-Bit Subspace Decomposition -/

/-- Lower 32-bit slice `x[31:0]` of a 64-bit word `x ∈ W64`. -/
def lo32 (x : BitVec 64) : BitVec 32 := x.truncate 32

/-- Upper 32-bit prefix `x[63:32]` of a 64-bit word `x ∈ W64`. -/
def hi32 (x : BitVec 64) : BitVec 32 := (x >>> 32).truncate 32

/-- Reconstructs a 64-bit word `(k << 32) | z` from its 32-bit subspace prefix `k` and lower slice `z`. -/
def mk64 (k z : BitVec 32) : BitVec 64 :=
  (k.zeroExtend 64 <<< 32) ||| z.zeroExtend 64

theorem lo32_mk64 (k z : BitVec 32) : lo32 (mk64 k z) = z := by
  unfold lo32 mk64
  bv_decide

theorem hi32_mk64 (k z : BitVec 32) : hi32 (mk64 k z) = k := by
  unfold hi32 mk64
  bv_decide

theorem mk64_hi32_lo32 (x : BitVec 64) : mk64 (hi32 x) (lo32 x) = x := by
  unfold mk64 hi32 lo32
  bv_decide

/-- Concretization `γ_u64([umin, umax])` of the unsigned 64-bit interval domain `A_u64`. -/
def mem_u64 (x umin umax : BitVec 64) : Prop :=
  umin ≤ x ∧ x ≤ umax

/-- Concretization `γ_s64([smin, smax])` of the signed 64-bit interval domain `A_s64` (Equation 17). -/
def mem_s64 (x smin smax : BitVec 64) : Prop :=
  BitVec.sle smin x ∧ BitVec.sle x smax

/-- Concretization `γ_u32([u32_min, u32_max])` of the unsigned 32-bit subregister domain `A_u32` (Equation 18). -/
def mem_u32 (x : BitVec 64) (u32_min u32_max : BitVec 32) : Prop :=
  u32_min ≤ lo32 x ∧ lo32 x ≤ u32_max

/-- Concretization `γ_s32([s32_min, s32_max])` of the signed 32-bit subregister domain `A_s32`. -/
def mem_s32 (x : BitVec 64) (s32_min s32_max : BitVec 32) : Prop :=
  BitVec.sle s32_min (lo32 x) ∧ BitVec.sle (lo32 x) s32_max

/-- Section 6.1(1): When `s64` does not cross zero (`smin ≤_u smax`), `γ_s64([smin, smax])`
is the single contiguous unsigned interval `[smin, smax]`. -/
theorem mem_s64_noncross_iff (x smin smax : BitVec 64)
    (hs : BitVec.sle smin smax) (hcross : smin ≤ smax) :
    mem_s64 x smin smax ↔ (smin ≤ x ∧ x ≤ smax) := by
  unfold mem_s64 at *
  bv_decide

/-- Section 6.1(1): When `s64` crosses zero (`smin <_s 0 ≤_s smax`, i.e., `¬(smin ≤_u smax)`),
`γ_s64([smin, smax])` splits into two disjoint unsigned intervals `[0, smax] ∪ [smin, U64_MAX]`. -/
theorem mem_s64_cross_iff (x smin smax : BitVec 64)
    (hs : BitVec.sle smin smax) (hcross : ¬(smin ≤ smax)) :
    mem_s64 x smin smax ↔ ((0#64 ≤ x ∧ x ≤ smax) ∨ (smin ≤ x ∧ x ≤ U64_MAX)) := by
  unfold mem_s64 U64_MAX at *
  bv_decide

/-- Upper 32-bit tristate number `t_hi` (`t >> 32`). -/
def Tnum.hi (t : Tnum) : Tnum :=
  { value := (t.value >>> 32) &&& LOWER_HALF
    mask  := (t.mask  >>> 32) &&& LOWER_HALF }

/-- Lower 32-bit tristate number `t_lo` (`tnum_subreg(t)`). -/
def Tnum.lo (t : Tnum) : Tnum :=
  { value := t.value &&& LOWER_HALF
    mask  := t.mask  &&& LOWER_HALF }

theorem Tnum.hi_wf (t : Tnum) (hwf : t.wf) : t.hi.wf := by
  unfold Tnum.hi Tnum.wf LOWER_HALF at *
  bv_decide

theorem Tnum.lo_wf (t : Tnum) (hwf : t.wf) : t.lo.wf := by
  unfold Tnum.lo Tnum.wf LOWER_HALF at *
  bv_decide

/-- Bitwise independence of `t_hi` and `t_lo`: a 64-bit word `x` belongs to `γ(t)` if and only if
its upper 32-bit prefix `hi32 x` belongs to `γ(t_hi)` and its lower 32-bit slice `lo32 x` belongs to `γ(t_lo)`. -/
theorem Tnum.mem_iff_hi_lo (t : Tnum) (x : BitVec 64) :
    Tnum.mem x t ↔
    (Tnum.mem ((hi32 x).zeroExtend 64) t.hi ∧ Tnum.mem ((lo32 x).zeroExtend 64) t.lo) := by
  unfold Tnum.mem Tnum.hi Tnum.lo hi32 lo32 LOWER_HALF
  bv_decide

theorem Tnum.mem_mk64_iff (t : Tnum) (k z : BitVec 32) :
    Tnum.mem (mk64 k z) t ↔
    (Tnum.mem (k.zeroExtend 64) t.hi ∧ Tnum.mem (z.zeroExtend 64) t.lo) := by
  unfold Tnum.mem Tnum.hi Tnum.lo mk64 LOWER_HALF
  bv_decide

/-! ## Section 6.2: Three-Stage Allwise Intersection Pipeline (`reg_bounds_intersect`) -/

/-- A 64-bit unsigned interval `[lo, hi] ⊆ W64`. -/
structure Interval64 where
  lo : BitVec 64
  hi : BitVec 64
  deriving DecidableEq, Repr

def Interval64.wf (I : Interval64) : Prop := I.lo ≤ I.hi
def Interval64.mem (x : BitVec 64) (I : Interval64) : Prop := I.lo ≤ x ∧ x ≤ I.hi

/-- A 32-bit unsigned interval `[lo, hi] ⊆ W32`. -/
structure Interval32 where
  lo : BitVec 32
  hi : BitVec 32
  deriving DecidableEq, Repr

def Interval32.wf (I : Interval32) : Prop := I.lo ≤ I.hi
def Interval32.mem (z : BitVec 32) (I : Interval32) : Prop := I.lo ≤ z ∧ z ≤ I.hi

/-- A Stage 2 decomposed candidate `(I_pi, K_pi)` where `I_pi ⊆ W32` constrains `x[31:0]`
and `K_pi ⊆ W32` constrains the 32-bit subspace prefix `x[63:32]`. -/
structure SubspaceCand where
  I_pi : Interval32
  K_pi : Interval32
  deriving DecidableEq, Repr

def SubspaceCand.wf (c : SubspaceCand) : Prop :=
  c.I_pi.wf ∧ c.K_pi.wf

def SubspaceCand.mem (x : BitVec 64) (c : SubspaceCand) : Prop :=
  c.I_pi.mem (lo32 x) ∧ c.K_pi.mem (hi32 x)

def max64 (a b : BitVec 64) : BitVec 64 := if a > b then a else b
def min64 (a b : BitVec 64) : BitVec 64 := if a < b then a else b
def max32 (a b : BitVec 32) : BitVec 32 := if a > b then a else b
def min32 (a b : BitVec 32) : BitVec 32 := if a < b then a else b

/-! ### Stage 1: 64-Bit and 32-Bit Interval Intersection (Equations 20 & 21) -/

/-- Standard intersection of two 64-bit unsigned intervals `[a_lo, a_hi] ∩ [b_lo, b_hi]`. -/
def intersect64 (a_lo a_hi b_lo b_hi : BitVec 64) : List Interval64 :=
  let lo := max64 a_lo b_lo
  let hi := min64 a_hi b_hi
  if lo ≤ hi then [⟨lo, hi⟩] else []

/-- Stage 1 (Equation 20): Intersects `u64 = [umin, umax]` and `s64 = [smin, smax]` into `I_64`
(containing at most two contiguous 64-bit intervals). -/
def stage1_i64 (umin umax smin smax : BitVec 64) : List Interval64 :=
  if smin ≤ smax then
    intersect64 umin umax smin smax
  else
    intersect64 umin umax 0#64 smax ++ intersect64 umin umax smin U64_MAX

/-- Standard intersection of two 32-bit unsigned intervals `[a_lo, a_hi] ∩ [b_lo, b_hi]`. -/
def intersect32 (a_lo a_hi b_lo b_hi : BitVec 32) : List Interval32 :=
  let lo := max32 a_lo b_lo
  let hi := min32 a_hi b_hi
  if lo ≤ hi then [⟨lo, hi⟩] else []

/-- Stage 1 (Equation 21): Intersects `u32 = [u32_min, u32_max]` and `s32 = [s32_min, s32_max]`
into `I_32` (containing at most two contiguous 32-bit intervals). -/
def stage1_i32 (u32_min u32_max s32_min s32_max : BitVec 32) : List Interval32 :=
  if s32_min ≤ s32_max then
    intersect32 u32_min u32_max s32_min s32_max
  else
    intersect32 u32_min u32_max 0#32 s32_max ++ intersect32 u32_min u32_max s32_min 0xFFFF_FFFF#32

theorem mem_intersect64_iff (a_lo a_hi b_lo b_hi x : BitVec 64) :
    (∃ I ∈ intersect64 a_lo a_hi b_lo b_hi, I.mem x) ↔
    (a_lo ≤ x ∧ x ≤ a_hi ∧ b_lo ≤ x ∧ x ≤ b_hi) := by
  unfold intersect64 Interval64.mem
  dsimp only
  split
  · simp only [List.mem_singleton, exists_eq_left]
    unfold max64 min64 at *
    bv_decide
  · simp only [List.not_mem_nil, false_and, exists_false, false_iff]
    unfold max64 min64 at *
    bv_decide

theorem wf_of_mem_intersect64 (a_lo a_hi b_lo b_hi : BitVec 64) (I : Interval64)
    (h : I ∈ intersect64 a_lo a_hi b_lo b_hi) : I.wf := by
  unfold intersect64 at h
  dsimp only at h
  split at h
  · simp only [List.mem_singleton] at h
    subst h
    exact ‹_›
  · contradiction

/-- **Stage 1 (64-bit) Exactness**: `I_64` contains `x` if and only if `x ∈ γ_u64 ∩ γ_s64`. -/
theorem stage1_i64_iff (umin umax smin smax x : BitVec 64)
    (hs64 : BitVec.sle smin smax) :
    (∃ I ∈ stage1_i64 umin umax smin smax, I.mem x) ↔
    (mem_u64 x umin umax ∧ mem_s64 x smin smax) := by
  unfold stage1_i64
  split
  · rename_i hcross
    rw [mem_intersect64_iff]
    unfold mem_u64 mem_s64 at *
    bv_decide
  · rename_i hcross
    simp only [List.mem_append, or_and_right, exists_or, mem_intersect64_iff]
    unfold mem_u64 mem_s64 U64_MAX at *
    bv_decide

theorem stage1_i64_wf (umin umax smin smax : BitVec 64) (I : Interval64)
    (h : I ∈ stage1_i64 umin umax smin smax) : I.wf := by
  unfold stage1_i64 at h
  split at h
  · exact wf_of_mem_intersect64 umin umax smin smax I h
  · simp only [List.mem_append] at h
    rcases h with h1 | h2
    · exact wf_of_mem_intersect64 umin umax 0#64 smax I h1
    · exact wf_of_mem_intersect64 umin umax smin U64_MAX I h2

theorem stage1_i64_length_le_two (umin umax smin smax : BitVec 64) :
    (stage1_i64 umin umax smin smax).length ≤ 2 := by
  unfold stage1_i64 intersect64
  dsimp only
  split <;> repeat (first | split | simp)

theorem mem_intersect32_iff (a_lo a_hi b_lo b_hi z : BitVec 32) :
    (∃ I ∈ intersect32 a_lo a_hi b_lo b_hi, I.mem z) ↔
    (a_lo ≤ z ∧ z ≤ a_hi ∧ b_lo ≤ z ∧ z ≤ b_hi) := by
  unfold intersect32 Interval32.mem
  dsimp only
  split
  · simp only [List.mem_singleton, exists_eq_left]
    unfold max32 min32 at *
    bv_decide
  · simp only [List.not_mem_nil, false_and, exists_false, false_iff]
    unfold max32 min32 at *
    bv_decide

theorem wf_of_mem_intersect32 (a_lo a_hi b_lo b_hi : BitVec 32) (I : Interval32)
    (h : I ∈ intersect32 a_lo a_hi b_lo b_hi) : I.wf := by
  unfold intersect32 at h
  dsimp only at h
  split at h
  · simp only [List.mem_singleton] at h
    subst h
    exact ‹_›
  · contradiction

/-- **Stage 1 (32-bit) Exactness**: `I_32` contains `lo32 x` if and only if `x ∈ γ_u32 ∩ γ_s32`. -/
theorem stage1_i32_iff (u32_min u32_max s32_min s32_max : BitVec 32) (x : BitVec 64)
    (hs32 : BitVec.sle s32_min s32_max) :
    (∃ I32 ∈ stage1_i32 u32_min u32_max s32_min s32_max, I32.mem (lo32 x)) ↔
    (mem_u32 x u32_min u32_max ∧ mem_s32 x s32_min s32_max) := by
  unfold stage1_i32
  split
  · rename_i hcross
    rw [mem_intersect32_iff]
    unfold mem_u32 mem_s32 at *
    bv_decide
  · rename_i hcross
    simp only [List.mem_append, or_and_right, exists_or, mem_intersect32_iff]
    unfold mem_u32 mem_s32 at *
    bv_decide

theorem stage1_i32_wf (u32_min u32_max s32_min s32_max : BitVec 32) (I32 : Interval32)
    (h : I32 ∈ stage1_i32 u32_min u32_max s32_min s32_max) : I32.wf := by
  unfold stage1_i32 at h
  split at h
  · exact wf_of_mem_intersect32 u32_min u32_max s32_min s32_max I32 h
  · simp only [List.mem_append] at h
    rcases h with h1 | h2
    · exact wf_of_mem_intersect32 u32_min u32_max 0#32 s32_max I32 h1
    · exact wf_of_mem_intersect32 u32_min u32_max s32_min 0xFFFF_FFFF#32 I32 h2

theorem stage1_i32_length_le_two (u32_min u32_max s32_min s32_max : BitVec 32) :
    (stage1_i32 u32_min u32_max s32_min s32_max).length ≤ 2 := by
  unfold stage1_i32 intersect32
  dsimp only
  split <;> repeat (first | split | simp)

/-! ### Stage 2: Subspace Projection and 32-Bit Bound Intersection (Equations 22 & 23, Figure 4) -/

/-- Stage 2 (Equation 22 & Figure 4): Decomposes a 64-bit interval `I = [x, y]` across 32-bit
subspace boundaries into at most three `(I_pi, K_pi)` candidates:
1. Single subspace (`x_hi = y_hi`): `([x_lo, y_lo], [x_hi, x_hi])`
2. Spanning multiple subspaces (`x_hi < y_hi`):
   - Left boundary `(I_left, K_left) = ([x_lo, 2^32 - 1], [x_hi, x_hi])`
   - Intermediate full subspaces `(I_mid, K_mid) = ([0, 2^32 - 1], [x_hi + 1, y_hi - 1])` (if `y_hi > x_hi + 1`)
   - Right boundary `(I_right, K_right) = ([0, y_lo], [y_hi, y_hi])` -/
def stage2_project_one (I : Interval64) : List SubspaceCand :=
  let x_hi := hi32 I.lo
  let x_lo := lo32 I.lo
  let y_hi := hi32 I.hi
  let y_lo := lo32 I.hi
  if x_hi == y_hi then
    [⟨⟨x_lo, y_lo⟩, ⟨x_hi, x_hi⟩⟩]
  else
    let left  : SubspaceCand := ⟨⟨x_lo, 0xFFFF_FFFF#32⟩, ⟨x_hi, x_hi⟩⟩
    let right : SubspaceCand := ⟨⟨0#32, y_lo⟩, ⟨y_hi, y_hi⟩⟩
    if x_hi + 1#32 < y_hi then
      let mid : SubspaceCand := ⟨⟨0#32, 0xFFFF_FFFF#32⟩, ⟨x_hi + 1#32, y_hi - 1#32⟩⟩
      [left, mid, right]
    else
      [left, right]

/-- **Subspace Decomposition Theorem (Section 6.1 & Stage 2)**:
For any well-formed 64-bit interval `I = [x, y]`, a 64-bit word `z` lies in `I` if and only if
`z` belongs to one of the projected candidates in `stage2_project_one I`. -/
theorem stage2_project_one_iff (I : Interval64) (z : BitVec 64) (hI : I.wf) :
    (∃ c ∈ stage2_project_one I, c.mem z) ↔ I.mem z := by
  unfold stage2_project_one SubspaceCand.mem Interval32.mem Interval64.mem Interval64.wf at *
  dsimp only
  split
  · simp only [List.mem_singleton, exists_eq_left]
    unfold hi32 lo32 at *
    bv_decide
  · split
    · simp only [List.mem_cons, List.not_mem_nil, or_false, exists_eq_or_imp, exists_eq_left]
      unfold hi32 lo32 at *
      bv_decide
    · simp only [List.mem_cons, List.not_mem_nil, or_false, exists_eq_or_imp, exists_eq_left]
      unfold hi32 lo32 at *
      bv_decide

theorem stage2_project_one_wf (I : Interval64) (c : SubspaceCand)
    (hI : I.wf) (hc : c ∈ stage2_project_one I) : c.wf := by
  unfold stage2_project_one at hc
  unfold Interval64.wf at hI
  dsimp only at hc
  split at hc
  · simp only [List.mem_singleton] at hc
    subst hc
    simp only [SubspaceCand.wf, Interval32.wf, hi32, lo32] at *
    bv_decide
  · split at hc
    · simp only [List.mem_cons, List.not_mem_nil, or_false] at hc
      rcases hc with rfl | rfl | rfl
      · simp only [SubspaceCand.wf, Interval32.wf, hi32, lo32] at *; bv_decide
      · simp only [SubspaceCand.wf, Interval32.wf, hi32] at *; bv_decide
      · simp only [SubspaceCand.wf, Interval32.wf, hi32, lo32] at *; bv_decide
    · simp only [List.mem_cons, List.not_mem_nil, or_false] at hc
      rcases hc with rfl | rfl
      · simp only [SubspaceCand.wf, Interval32.wf, hi32, lo32] at *; bv_decide
      · simp only [SubspaceCand.wf, Interval32.wf, hi32, lo32] at *; bv_decide

theorem stage2_project_one_length_le_three (I : Interval64) :
    (stage2_project_one I).length ≤ 3 := by
  unfold stage2_project_one
  dsimp only
  split <;> repeat (first | split | simp)

/-- Stage 2 (Equation 23): Intersects a projected candidate `(I_pi, K_pi)` with a target 32-bit interval `I_32`. -/
def narrow_cand (c : SubspaceCand) (I32 : Interval32) : List SubspaceCand :=
  let lo := max32 c.I_pi.lo I32.lo
  let hi := min32 c.I_pi.hi I32.hi
  if lo ≤ hi then
    [⟨⟨lo, hi⟩, c.K_pi⟩]
  else
    []

theorem narrow_cand_iff (c : SubspaceCand) (I32 : Interval32) (x : BitVec 64) :
    (∃ c' ∈ narrow_cand c I32, c'.mem x) ↔ (c.mem x ∧ I32.mem (lo32 x)) := by
  unfold narrow_cand SubspaceCand.mem Interval32.mem
  dsimp only
  split
  · simp only [List.mem_singleton, exists_eq_left]
    unfold max32 min32 at *
    bv_decide
  · simp only [List.not_mem_nil, false_and, exists_false, false_iff]
    unfold max32 min32 at *
    bv_decide

theorem narrow_cand_wf (c : SubspaceCand) (I32 : Interval32) (c' : SubspaceCand)
    (hc : c.wf) (h : c' ∈ narrow_cand c I32) : c'.wf := by
  unfold narrow_cand at h
  dsimp only at h
  split at h
  · simp only [List.mem_singleton] at h
    subst h
    exact ⟨‹_›, hc.2⟩
  · contradiction

/-- Stage 2 candidate set `I_pi` (Equation 22): at most `2 * 3 = 6` projected candidates. -/
def stage2_project (I64 : List Interval64) : List SubspaceCand :=
  I64.flatMap stage2_project_one

/-- Stage 2 final candidate set `J` (Equation 23): at most `6 * 2 = 12` narrowed candidates. -/
def stage2_narrow (I_pi : List SubspaceCand) (I32 : List Interval32) : List SubspaceCand :=
  I_pi.flatMap (fun c => I32.flatMap (fun i32 => narrow_cand c i32))

/-- Allwise candidate set `J` constructed by Stages 1 and 2 from the four interval domains. -/
def allwise_candidates (umin umax smin smax : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) : List SubspaceCand :=
  let I64 := stage1_i64 umin umax smin smax
  let I32 := stage1_i32 u32_min u32_max s32_min s32_max
  stage2_narrow (stage2_project I64) I32

/-- **Stage 2 Exactness**: A 64-bit word `x` belongs to all four interval domains
(`u64 ∩ s64 ∩ u32 ∩ s32`) if and only if `x` belongs to some candidate `(I_pi, K_pi) ∈ J`. -/
theorem allwise_candidates_iff (umin umax smin smax x : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32)
    (hs64 : BitVec.sle smin smax) (hs32 : BitVec.sle s32_min s32_max) :
    (∃ c ∈ allwise_candidates umin umax smin smax u32_min u32_max s32_min s32_max, c.mem x) ↔
    (mem_u64 x umin umax ∧ mem_s64 x smin smax ∧
     mem_u32 x u32_min u32_max ∧ mem_s32 x s32_min s32_max) := by
  unfold allwise_candidates stage2_narrow stage2_project
  simp only [List.mem_flatMap]
  constructor
  · rintro ⟨c', ⟨c, ⟨I, hI_mem, hc_mem⟩, I32, hI32_mem, hc'_mem⟩, hx_c'⟩
    have hI_wf : I.wf := stage1_i64_wf umin umax smin smax I hI_mem
    have ⟨hx_c, hx_I32⟩ := (narrow_cand_iff c I32 x).mp ⟨c', hc'_mem, hx_c'⟩
    have hx_I : I.mem x := (stage2_project_one_iff I x hI_wf).mp ⟨c, hc_mem, hx_c⟩
    have ⟨hu64, hs64_m⟩ := (stage1_i64_iff umin umax smin smax x hs64).mp ⟨I, hI_mem, hx_I⟩
    have ⟨hu32, hs32_m⟩ := (stage1_i32_iff u32_min u32_max s32_min s32_max x hs32).mp ⟨I32, hI32_mem, hx_I32⟩
    exact ⟨hu64, hs64_m, hu32, hs32_m⟩
  · rintro ⟨hu64, hs64_m, hu32, hs32_m⟩
    have ⟨I, hI_mem, hx_I⟩ := (stage1_i64_iff umin umax smin smax x hs64).mpr ⟨hu64, hs64_m⟩
    have hI_wf : I.wf := stage1_i64_wf umin umax smin smax I hI_mem
    have ⟨c, hc_mem, hx_c⟩ := (stage2_project_one_iff I x hI_wf).mpr hx_I
    have ⟨I32, hI32_mem, hx_I32⟩ := (stage1_i32_iff u32_min u32_max s32_min s32_max x hs32).mpr ⟨hu32, hs32_m⟩
    have ⟨c', hc'_mem, hx_c'⟩ := (narrow_cand_iff c I32 x).mpr ⟨hx_c, hx_I32⟩
    exact ⟨c', ⟨c, ⟨I, hI_mem, hc_mem⟩, I32, hI32_mem, hc'_mem⟩, hx_c'⟩

theorem allwise_candidates_wf (umin umax smin smax : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) (c' : SubspaceCand)
    (h : c' ∈ allwise_candidates umin umax smin smax u32_min u32_max s32_min s32_max) :
    c'.wf := by
  unfold allwise_candidates stage2_narrow stage2_project at h
  simp only [List.mem_flatMap] at h
  rcases h with ⟨c, ⟨I, hI_mem, hc_mem⟩, I32, _, hc'_mem⟩
  have hI_wf : I.wf := stage1_i64_wf umin umax smin smax I hI_mem
  have hc_wf : c.wf := stage2_project_one_wf I c hI_wf hc_mem
  exact narrow_cand_wf c I32 c' hc_wf hc'_mem

/-! ### Stage 3: Tristate Number Stepping (Equations 24 & 25, Figure 5) -/

/-- Stage 3 check for a single candidate `(I_pi = [a, b], K_pi = [k_min, k_max]) ∈ J`:
1. Prefix compatibility (Equation 24): checks whether `K_pi` intersects `t_hi` via `tnum_u64_intersect`.
2. Lower 32-bit tristate intersection (Equation 25): checks whether `I_pi` intersects `t_lo` via `tnum_u64_intersect`. -/
def stage3_check_cand (t : Tnum) (c : SubspaceCand) : Bool :=
  tnum_u64_intersect t.hi (c.K_pi.lo.zeroExtend 64) (c.K_pi.hi.zeroExtend 64) &&
  tnum_u64_intersect t.lo (c.I_pi.lo.zeroExtend 64) (c.I_pi.hi.zeroExtend 64)

private theorem cand_reconstruct_witness (t : Tnum) (c : SubspaceCand) (k64 z64 : BitVec 64)
    (hk_mem : Tnum.mem k64 t.hi)
    (hk_lo : c.K_pi.lo.zeroExtend 64 ≤ k64) (hk_hi : k64 ≤ c.K_pi.hi.zeroExtend 64)
    (hz_mem : Tnum.mem z64 t.lo)
    (hz_lo : c.I_pi.lo.zeroExtend 64 ≤ z64) (hz_hi : z64 ≤ c.I_pi.hi.zeroExtend 64) :
    let x := mk64 (k64.truncate 32) (z64.truncate 32)
    c.mem x ∧ Tnum.mem x t := by
  unfold SubspaceCand.mem Interval32.mem Tnum.mem Tnum.hi Tnum.lo mk64 hi32 lo32 LOWER_HALF at *
  bv_decide

private theorem cand_project_witness (t : Tnum) (c : SubspaceCand) (x : BitVec 64)
    (hc_mem : c.mem x) (ht_mem : Tnum.mem x t) :
    (Tnum.mem ((hi32 x).zeroExtend 64) t.hi ∧
     c.K_pi.lo.zeroExtend 64 ≤ (hi32 x).zeroExtend 64 ∧
     (hi32 x).zeroExtend 64 ≤ c.K_pi.hi.zeroExtend 64) ∧
    (Tnum.mem ((lo32 x).zeroExtend 64) t.lo ∧
     c.I_pi.lo.zeroExtend 64 ≤ (lo32 x).zeroExtend 64 ∧
     (lo32 x).zeroExtend 64 ≤ c.I_pi.hi.zeroExtend 64) := by
  unfold SubspaceCand.mem Interval32.mem Tnum.mem Tnum.hi Tnum.lo hi32 lo32 LOWER_HALF at *
  bv_decide

/-- **Stage 3 Candidate Exactness**:
For any well-formed `t` and well-formed candidate `c = (I_pi, K_pi)`, `stage3_check_cand t c = true`
if and only if there exists a 64-bit word `x ∈ W64` satisfying both `c.mem x` and `x ∈ γ(t)`. -/
theorem stage3_check_cand_iff (t : Tnum) (c : SubspaceCand)
    (hwf : t.wf) (hc : c.wf) :
    stage3_check_cand t c = true ↔ (∃ x : BitVec 64, c.mem x ∧ Tnum.mem x t) := by
  unfold stage3_check_cand
  rw [Bool.and_eq_true]
  constructor
  · rintro ⟨h_hi, h_lo⟩
    have hK_range : c.K_pi.lo.zeroExtend 64 ≤ c.K_pi.hi.zeroExtend 64 := by
      have := hc.2; unfold Interval32.wf at this; bv_decide
    have hI_range : c.I_pi.lo.zeroExtend 64 ≤ c.I_pi.hi.zeroExtend 64 := by
      have := hc.1; unfold Interval32.wf at this; bv_decide
    have ⟨k64, hk_mem, hk_lo, hk_hi⟩ :=
      tnum_u64_intersect_sound t.hi (c.K_pi.lo.zeroExtend 64) (c.K_pi.hi.zeroExtend 64)
        (Tnum.hi_wf t hwf) hK_range h_hi
    have ⟨z64, hz_mem, hz_lo, hz_hi⟩ :=
      tnum_u64_intersect_sound t.lo (c.I_pi.lo.zeroExtend 64) (c.I_pi.hi.zeroExtend 64)
        (Tnum.lo_wf t hwf) hI_range h_lo
    exact ⟨mk64 (k64.truncate 32) (z64.truncate 32),
           cand_reconstruct_witness t c k64 z64 hk_mem hk_lo hk_hi hz_mem hz_lo hz_hi⟩
  · rintro ⟨x, hc_mem, ht_mem⟩
    have ⟨⟨hk_mem, hk_lo, hk_hi⟩, ⟨hz_mem, hz_lo, hz_hi⟩⟩ :=
      cand_project_witness t c x hc_mem ht_mem
    exact ⟨tnum_u64_intersect_complete t.hi (c.K_pi.lo.zeroExtend 64) (c.K_pi.hi.zeroExtend 64)
             ((hi32 x).zeroExtend 64) (Tnum.hi_wf t hwf) hk_mem hk_lo hk_hi,
           tnum_u64_intersect_complete t.lo (c.I_pi.lo.zeroExtend 64) (c.I_pi.hi.zeroExtend 64)
             ((lo32 x).zeroExtend 64) (Tnum.lo_wf t hwf) hz_mem hz_lo hz_hi⟩

/-- **Complete Three-Stage Allwise Intersection Decision Procedure (`reg_bounds_intersect`, Section 6.2)**:
Evaluates Stage 1 (`I_64`, `I_32`), Stage 2 (`I_pi`, `J`), and Stage 3 (`stage3_check_cand`) across
all five eBPF abstract domains (`u64`, `s64`, `u32`, `s32`, `tnum`). -/
def reg_bounds_intersect (umin umax smin smax : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) (t : Tnum) : Bool :=
  (allwise_candidates umin umax smin smax u32_min u32_max s32_min s32_max).any (stage3_check_cand t)

/-- **Soundness of `reg_bounds_intersect` (Common Member Existence — CM)**:
If `reg_bounds_intersect` returns `true`, then the all-wise intersection
`γ_u64 ∩ γ_s64 ∩ γ_u32 ∩ γ_s32 ∩ γ_tnum(t)` is non-empty. -/
theorem reg_bounds_intersect_sound (umin umax smin smax : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) (t : Tnum)
    (hwf : t.wf) (hs64 : BitVec.sle smin smax) (hs32 : BitVec.sle s32_min s32_max)
    (h : reg_bounds_intersect umin umax smin smax u32_min u32_max s32_min s32_max t = true) :
    ∃ x : BitVec 64,
      mem_u64 x umin umax ∧ mem_s64 x smin smax ∧
      mem_u32 x u32_min u32_max ∧ mem_s32 x s32_min s32_max ∧
      Tnum.mem x t := by
  unfold reg_bounds_intersect at h
  rw [List.any_eq_true] at h
  rcases h with ⟨c, hc_in, hc_ok⟩
  have hc_wf : c.wf := allwise_candidates_wf umin umax smin smax u32_min u32_max s32_min s32_max c hc_in
  have ⟨x, hx_c, hx_t⟩ := (stage3_check_cand_iff t c hwf hc_wf).mp hc_ok
  have ⟨hu64, hs64_m, hu32, hs32_m⟩ :=
    (allwise_candidates_iff umin umax smin smax x u32_min u32_max s32_min s32_max hs64 hs32).mp
      ⟨c, hc_in, hx_c⟩
  exact ⟨x, hu64, hs64_m, hu32, hs32_m, hx_t⟩

/-- **Completeness of `reg_bounds_intersect` (Empty Intersection Soundness — EI)**:
Whenever there exists `x ∈ γ_u64 ∩ γ_s64 ∩ γ_u32 ∩ γ_s32 ∩ γ_tnum(t)`,
`reg_bounds_intersect` returns `true` (so if it returns `false`, the intersection is provably empty). -/
theorem reg_bounds_intersect_complete (umin umax smin smax x : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) (t : Tnum)
    (hwf : t.wf) (hs64 : BitVec.sle smin smax) (hs32 : BitVec.sle s32_min s32_max)
    (hu64 : mem_u64 x umin umax) (hs64_m : mem_s64 x smin smax)
    (hu32 : mem_u32 x u32_min u32_max) (hs32_m : mem_s32 x s32_min s32_max)
    (ht : Tnum.mem x t) :
    reg_bounds_intersect umin umax smin smax u32_min u32_max s32_min s32_max t = true := by
  unfold reg_bounds_intersect
  rw [List.any_eq_true]
  have ⟨c, hc_in, hx_c⟩ :=
    (allwise_candidates_iff umin umax smin smax x u32_min u32_max s32_min s32_max hs64 hs32).mpr
      ⟨hu64, hs64_m, hu32, hs32_m⟩
  have hc_wf : c.wf := allwise_candidates_wf umin umax smin smax u32_min u32_max s32_min s32_max c hc_in
  exact ⟨c, hc_in, (stage3_check_cand_iff t c hwf hc_wf).mpr ⟨x, hx_c, ht⟩⟩

/-- **Soundness and Completeness of Allwise Set Intersection in eBPF (`reg_bounds_intersect_iff`)**:
For any well-formed register state, `reg_bounds_intersect` returns `true` if and only if
the allwise intersection `γ_u64([umin, umax]) ∩ γ_s64([smin, smax]) ∩ γ_u32([u32_min, u32_max]) ∩ γ_s32([s32_min, s32_max]) ∩ γ_tnum(t)` is non-empty. -/
theorem reg_bounds_intersect_iff (umin umax smin smax : BitVec 64)
    (u32_min u32_max s32_min s32_max : BitVec 32) (t : Tnum)
    (hwf : t.wf) (hs64 : BitVec.sle smin smax) (hs32 : BitVec.sle s32_min s32_max) :
    reg_bounds_intersect umin umax smin smax u32_min u32_max s32_min s32_max t = true ↔
    (∃ x : BitVec 64,
      mem_u64 x umin umax ∧ mem_s64 x smin smax ∧
      mem_u32 x u32_min u32_max ∧ mem_s32 x s32_min s32_max ∧
      Tnum.mem x t) :=
  ⟨reg_bounds_intersect_sound umin umax smin smax u32_min u32_max s32_min s32_max t hwf hs64 hs32,
   fun ⟨x, hu64, hs64_m, hu32, hs32_m, ht⟩ =>
     reg_bounds_intersect_complete umin umax smin smax x u32_min u32_max s32_min s32_max t
       hwf hs64 hs32 hu64 hs64_m hu32 hs32_m ht⟩

/-! ## Concrete Regression Tests & Figure 6 Walkthrough (Examples 1 & 2) -/

-- Basic tnum_step path tests
#guard tnum_step { value := 0b0010#64, mask := 0b0100#64 } 0b0110#64 == 0b0110#64
#guard tnum_step { value := 0b0010#64, mask := 0b0100#64 } 0b0001#64 == 0b0010#64
#guard tnum_step { value := 0b1010#64, mask := 0b0101#64 } 0b1001#64 == 0b1010#64
#guard tnum_step { value := 0b0010#64, mask := 0b0100#64 } 0b0010#64 == 0b0110#64
#guard tnum_step { value := 0b0010#64, mask := 0b0100#64 } 0b0011#64 == 0b0110#64

-- Figure 6, Example 1: Non-empty intersection
-- u64 = [1, 2*2^32 + 5], s64 = [-10, 2*2^32 + 5], u32 = [10, 20], s32 = [10, 20]
-- t.v = 0x0000000100000000, t.m = 0xfffffffefffffff0 (upper 32 bits odd, lower 32 bits multiples of 16)
#guard stage1_i64 1#64 0x0000_0002_0000_0005#64 (-10#64) 0x0000_0002_0000_0005#64 ==
  [⟨1#64, 0x0000_0002_0000_0005#64⟩]
#guard stage1_i32 10#32 20#32 10#32 20#32 ==
  [⟨10#32, 20#32⟩]
#guard allwise_candidates 1#64 0x0000_0002_0000_0005#64 (-10#64) 0x0000_0002_0000_0005#64 10#32 20#32 10#32 20#32 ==
  [⟨⟨10#32, 20#32⟩, ⟨0#32, 0#32⟩⟩, ⟨⟨10#32, 20#32⟩, ⟨1#32, 1#32⟩⟩]
#guard reg_bounds_intersect 1#64 0x0000_0002_0000_0005#64 (-10#64) 0x0000_0002_0000_0005#64
  10#32 20#32 10#32 20#32
  { value := 0x0000_0001_0000_0000#64, mask := 0xFFFF_FFFE_FFFF_FFF0#64 } == true

-- Figure 6, Example 2: Empty intersection (t_lo requires multiples of 32: tnum_step(t_lo, 10) = 32 > 20)
#guard reg_bounds_intersect 1#64 0x0000_0002_0000_0005#64 (-10#64) 0x0000_0002_0000_0005#64
  10#32 20#32 10#32 20#32
  { value := 0x0000_0001_0000_0000#64, mask := 0xFFFF_FFFE_FFFF_FFE0#64 } == false

end TnumStep
