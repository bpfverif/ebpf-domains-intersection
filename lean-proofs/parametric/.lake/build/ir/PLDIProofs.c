// Lean compiler output
// Module: PLDIProofs
// Imports: public import Init public meta import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l_BitVec_ofNat(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_to_list(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
uint8_t l_BitVec_slt(lean_object*, lean_object*, lean_object*);
uint8_t l_BitVec_sle(lean_object*, lean_object*, lean_object*);
lean_object* l_BitVec_allOnes(lean_object*);
lean_object* l_BitVec_extractLsb_x27___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_BitVec_not(lean_object*, lean_object*);
lean_object* lean_nat_land(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_BitVec_repr(lean_object*, lean_object*);
lean_object* lean_string_length(lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
size_t lean_usize_sub(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
lean_object* lean_nat_lor(lean_object*, lean_object*);
lean_object* l_BitVec_setWidth(lean_object*, lean_object*, lean_object*);
lean_object* l_BitVec_cons(lean_object*, uint8_t, lean_object*);
uint8_t l_Nat_testBit(lean_object*, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* lean_array_get_size(lean_object*);
size_t lean_usize_of_nat(lean_object*);
lean_object* l_BitVec_shiftLeft(lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_BitVec_add(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_hiSlice(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_hiSlice___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_mkWord(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_mkWord___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__0_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "min"};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__1_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__1_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__2_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__3_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__4 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__4_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__4_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__3_value),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__6_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7;
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__8 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__8_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__8_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "max"};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__10 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__10_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__10_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__11 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__11_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__12 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__12_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__12_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16 = (const lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval(lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "smin"};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__0_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__1_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__1_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__2_value),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__3_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4;
static const lean_string_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "smax"};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__5_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__6_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval(lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum_decEq(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "v"};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__0_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__1_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__1_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__2_value),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__3_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4;
static const lean_string_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "m"};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__5_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__6_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum(lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf___redArg___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaU___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaU___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaU(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaU___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaS(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaS___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaTnum(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaTnum___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaUSub(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaUSub___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaSSub(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaSSub___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState_decEq(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "u64"};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__0_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__1_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__1_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__2_value),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__3_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "s64"};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__4 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__4_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__4_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__5_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "u32"};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__6_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__6_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__7 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__7_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "s32"};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__8 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__8_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__8_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__9 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__9_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tnum"};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__10 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__10_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__10_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__11 = (const lean_object*)&lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__11_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaReg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaReg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWF(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWF___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableIF__state(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableIF__state___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__1;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__2;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__3;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__4;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__5;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__6;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__7;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__8;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R0___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R0___closed__9;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_motivating__R0;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R1__EI___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R1__EI___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R1__EI___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R1__EI___closed__1;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_motivating__R1__EI;
static lean_once_cell_t lp_parametric_PLDIProofs_motivating__R2__IF___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_motivating__R2__IF___closed__0;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_motivating__R2__IF;
static lean_once_cell_t lp_parametric_PLDIProofs_tnum__step___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_tnum__step___closed__0;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnum__step(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnum__step___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumSteppableDomain(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_find_x3f___at___00PLDIProofs_multiDomainLoop_spec__0(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multiDomainLoop___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multiDomainLoop___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multiDomainLoop(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multiDomainLoop___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMin(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMin___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMax(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMax___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0(lean_object*, lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multi__domain__intersect(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multi__domain__intersect___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_unrolledIntervalListIntersect(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_unrolledIntervalListIntersect___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_fig3__D1___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D1___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D1___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D1___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D1___closed__1;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D1___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D1___closed__2;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D1___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D1___closed__3;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D1___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D1___closed__4;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1;
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_fig3__D2___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D2___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D2___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D2___closed__1;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D2___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D2___closed__2;
static lean_once_cell_t lp_parametric_PLDIProofs_fig3__D2___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig3__D2___closed__3;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2;
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_SInterval_crossesZero(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_SInterval_crossesZero___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumHi(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumHi___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "kRange"};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__0_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__1_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__1_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__2_value),((lean_object*)&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__3_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4;
static const lean_string_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "subRange"};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__5_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__5_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__6_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_projectInterval(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_projectInterval___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___redArg(lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_parametric_PLDIProofs_stage1__width___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_parametric_PLDIProofs_stage1__width___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_stage1__width___closed__0_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__width(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__width___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__full(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__full___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object lp_parametric_PLDIProofs_stage2__project___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* lp_parametric_PLDIProofs_stage2__project___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_stage2__project___closed__0_value;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__project(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__project___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__narrow(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__narrow___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_tnumIntersectsInterval(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumIntersectsInterval___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_checkBoxAgainstTnum(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_checkBoxAgainstTnum___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_reg__bounds__intersect(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_reg__bounds__intersect___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__1;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__2;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__3;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__4;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__5;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__6;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__7;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__8;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__9;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example1__state___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example1__state___closed__10;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig6__example1__state;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__0;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__1;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__2;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__3;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__4;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__5;
static lean_once_cell_t lp_parametric_PLDIProofs_fig6__example2__state___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_fig6__example2__state___closed__6;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig6__example2__state;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorIdx(uint8_t);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_BranchResolution_ofNat(lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ofNat___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqBranchResolution(uint8_t, uint8_t);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqBranchResolution___boxed(lean_object*, lean_object*);
static const lean_string_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "PLDIProofs.BranchResolution.takenOnly"};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__0_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__0_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__1 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__1_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 44, .m_capacity = 44, .m_length = 43, .m_data = "PLDIProofs.BranchResolution.fallthroughOnly"};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__2 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__2_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__2_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__3 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__3_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 41, .m_capacity = 41, .m_length = 40, .m_data = "PLDIProofs.BranchResolution.bothFeasible"};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__4 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__4_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__4_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__5 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__5_value;
static const lean_string_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 44, .m_capacity = 44, .m_length = 43, .m_data = "PLDIProofs.BranchResolution.unreachableNode"};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__6 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__6_value;
static const lean_ctor_object lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__6_value)}};
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__7 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__7_value;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8;
static lean_once_cell_t lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9;
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr(uint8_t, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_parametric_PLDIProofs_instReprBranchResolution___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_parametric_PLDIProofs_instReprBranchResolution_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution___closed__0 = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution___closed__0_value;
LEAN_EXPORT const lean_object* lp_parametric_PLDIProofs_instReprBranchResolution = (const lean_object*)&lp_parametric_PLDIProofs_instReprBranchResolution___closed__0_value;
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_simulate__both__branches__taken(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_simulate__both__branches__taken___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___redArg(lean_object* v_w__lo_1_, lean_object* v_x_2_){
_start:
{
lean_object* v___x_3_; lean_object* v___x_4_; 
v___x_3_ = lean_unsigned_to_nat(0u);
v___x_4_ = l_BitVec_extractLsb_x27___redArg(v___x_3_, v_w__lo_1_, v_x_2_);
return v___x_4_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___redArg___boxed(lean_object* v_w__lo_5_, lean_object* v_x_6_){
_start:
{
lean_object* v_res_7_; 
v_res_7_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_5_, v_x_6_);
lean_dec(v_x_6_);
lean_dec(v_w__lo_5_);
return v_res_7_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice(lean_object* v_w__lo_8_, lean_object* v_w__hi_9_, lean_object* v_x_10_){
_start:
{
lean_object* v___x_11_; 
v___x_11_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_8_, v_x_10_);
return v___x_11_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_loSlice___boxed(lean_object* v_w__lo_12_, lean_object* v_w__hi_13_, lean_object* v_x_14_){
_start:
{
lean_object* v_res_15_; 
v_res_15_ = lp_parametric_PLDIProofs_loSlice(v_w__lo_12_, v_w__hi_13_, v_x_14_);
lean_dec(v_x_14_);
lean_dec(v_w__hi_13_);
lean_dec(v_w__lo_12_);
return v_res_15_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_hiSlice(lean_object* v_w__lo_16_, lean_object* v_w__hi_17_, lean_object* v_x_18_){
_start:
{
lean_object* v___x_19_; 
v___x_19_ = l_BitVec_extractLsb_x27___redArg(v_w__lo_16_, v_w__hi_17_, v_x_18_);
return v___x_19_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_hiSlice___boxed(lean_object* v_w__lo_20_, lean_object* v_w__hi_21_, lean_object* v_x_22_){
_start:
{
lean_object* v_res_23_; 
v_res_23_ = lp_parametric_PLDIProofs_hiSlice(v_w__lo_20_, v_w__hi_21_, v_x_22_);
lean_dec(v_x_22_);
lean_dec(v_w__hi_21_);
lean_dec(v_w__lo_20_);
return v_res_23_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_mkWord(lean_object* v_w__lo_24_, lean_object* v_w__hi_25_, lean_object* v_k_26_, lean_object* v_lo_27_){
_start:
{
lean_object* v___x_28_; lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_28_ = lean_nat_add(v_w__lo_24_, v_w__hi_25_);
v___x_29_ = l_BitVec_setWidth(v_w__hi_25_, v___x_28_, v_k_26_);
v___x_30_ = l_BitVec_shiftLeft(v___x_28_, v___x_29_, v_w__lo_24_);
lean_dec(v___x_29_);
v___x_31_ = l_BitVec_setWidth(v_w__lo_24_, v___x_28_, v_lo_27_);
lean_dec(v___x_28_);
v___x_32_ = lean_nat_lor(v___x_30_, v___x_31_);
lean_dec(v___x_31_);
lean_dec(v___x_30_);
return v___x_32_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_mkWord___boxed(lean_object* v_w__lo_33_, lean_object* v_w__hi_34_, lean_object* v_k_35_, lean_object* v_lo_36_){
_start:
{
lean_object* v_res_37_; 
v_res_37_ = lp_parametric_PLDIProofs_mkWord(v_w__lo_33_, v_w__hi_34_, v_k_35_, v_lo_36_);
lean_dec(v_lo_36_);
lean_dec(v_k_35_);
lean_dec(v_w__hi_34_);
lean_dec(v_w__lo_33_);
return v_res_37_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(lean_object* v_x_38_, lean_object* v_x_39_){
_start:
{
lean_object* v_min_40_; lean_object* v_max_41_; lean_object* v_min_42_; lean_object* v_max_43_; uint8_t v___x_44_; 
v_min_40_ = lean_ctor_get(v_x_38_, 0);
v_max_41_ = lean_ctor_get(v_x_38_, 1);
v_min_42_ = lean_ctor_get(v_x_39_, 0);
v_max_43_ = lean_ctor_get(v_x_39_, 1);
v___x_44_ = lean_nat_dec_eq(v_min_40_, v_min_42_);
if (v___x_44_ == 0)
{
return v___x_44_;
}
else
{
uint8_t v___x_45_; 
v___x_45_ = lean_nat_dec_eq(v_max_41_, v_max_43_);
return v___x_45_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg___boxed(lean_object* v_x_46_, lean_object* v_x_47_){
_start:
{
uint8_t v_res_48_; lean_object* v_r_49_; 
v_res_48_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_x_46_, v_x_47_);
lean_dec_ref(v_x_47_);
lean_dec_ref(v_x_46_);
v_r_49_ = lean_box(v_res_48_);
return v_r_49_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq(lean_object* v_w_50_, lean_object* v_x_51_, lean_object* v_x_52_){
_start:
{
uint8_t v___x_53_; 
v___x_53_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_x_51_, v_x_52_);
return v___x_53_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___boxed(lean_object* v_w_54_, lean_object* v_x_55_, lean_object* v_x_56_){
_start:
{
uint8_t v_res_57_; lean_object* v_r_58_; 
v_res_57_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq(v_w_54_, v_x_55_, v_x_56_);
lean_dec_ref(v_x_56_);
lean_dec_ref(v_x_55_);
lean_dec(v_w_54_);
v_r_58_ = lean_box(v_res_57_);
return v_r_58_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval___redArg(lean_object* v_x_59_, lean_object* v_x_60_){
_start:
{
uint8_t v___x_61_; 
v___x_61_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_x_59_, v_x_60_);
return v___x_61_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval___redArg___boxed(lean_object* v_x_62_, lean_object* v_x_63_){
_start:
{
uint8_t v_res_64_; lean_object* v_r_65_; 
v_res_64_ = lp_parametric_PLDIProofs_instDecidableEqUInterval___redArg(v_x_62_, v_x_63_);
lean_dec_ref(v_x_63_);
lean_dec_ref(v_x_62_);
v_r_65_ = lean_box(v_res_64_);
return v_r_65_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqUInterval(lean_object* v_w_66_, lean_object* v_x_67_, lean_object* v_x_68_){
_start:
{
uint8_t v___x_69_; 
v___x_69_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_x_67_, v_x_68_);
return v___x_69_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqUInterval___boxed(lean_object* v_w_70_, lean_object* v_x_71_, lean_object* v_x_72_){
_start:
{
uint8_t v_res_73_; lean_object* v_r_74_; 
v_res_73_ = lp_parametric_PLDIProofs_instDecidableEqUInterval(v_w_70_, v_x_71_, v_x_72_);
lean_dec_ref(v_x_72_);
lean_dec_ref(v_x_71_);
lean_dec(v_w_70_);
v_r_74_ = lean_box(v_res_73_);
return v_r_74_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_88_; lean_object* v___x_89_; 
v___x_88_ = lean_unsigned_to_nat(7u);
v___x_89_ = lean_nat_to_int(v___x_88_);
return v___x_89_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13(void){
_start:
{
lean_object* v___x_97_; lean_object* v___x_98_; 
v___x_97_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__0));
v___x_98_ = lean_string_length(v___x_97_);
return v___x_98_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14(void){
_start:
{
lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_99_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__13);
v___x_100_ = lean_nat_to_int(v___x_99_);
return v___x_100_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(lean_object* v_w_105_, lean_object* v_x_106_){
_start:
{
lean_object* v_min_107_; lean_object* v_max_108_; lean_object* v___x_110_; uint8_t v_isShared_111_; uint8_t v_isSharedCheck_140_; 
v_min_107_ = lean_ctor_get(v_x_106_, 0);
v_max_108_ = lean_ctor_get(v_x_106_, 1);
v_isSharedCheck_140_ = !lean_is_exclusive(v_x_106_);
if (v_isSharedCheck_140_ == 0)
{
v___x_110_ = v_x_106_;
v_isShared_111_ = v_isSharedCheck_140_;
goto v_resetjp_109_;
}
else
{
lean_inc(v_max_108_);
lean_inc(v_min_107_);
lean_dec(v_x_106_);
v___x_110_ = lean_box(0);
v_isShared_111_ = v_isSharedCheck_140_;
goto v_resetjp_109_;
}
v_resetjp_109_:
{
lean_object* v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_117_; 
v___x_112_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5));
v___x_113_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__6));
v___x_114_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7);
lean_inc(v_w_105_);
v___x_115_ = l_BitVec_repr(v_w_105_, v_min_107_);
if (v_isShared_111_ == 0)
{
lean_ctor_set_tag(v___x_110_, 4);
lean_ctor_set(v___x_110_, 1, v___x_115_);
lean_ctor_set(v___x_110_, 0, v___x_114_);
v___x_117_ = v___x_110_;
goto v_reusejp_116_;
}
else
{
lean_object* v_reuseFailAlloc_139_; 
v_reuseFailAlloc_139_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_139_, 0, v___x_114_);
lean_ctor_set(v_reuseFailAlloc_139_, 1, v___x_115_);
v___x_117_ = v_reuseFailAlloc_139_;
goto v_reusejp_116_;
}
v_reusejp_116_:
{
uint8_t v___x_118_; lean_object* v___x_119_; lean_object* v___x_120_; lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_124_; lean_object* v___x_125_; lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; 
v___x_118_ = 0;
v___x_119_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_119_, 0, v___x_117_);
lean_ctor_set_uint8(v___x_119_, sizeof(void*)*1, v___x_118_);
v___x_120_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_120_, 0, v___x_113_);
lean_ctor_set(v___x_120_, 1, v___x_119_);
v___x_121_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9));
v___x_122_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_122_, 0, v___x_120_);
lean_ctor_set(v___x_122_, 1, v___x_121_);
v___x_123_ = lean_box(1);
v___x_124_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_124_, 0, v___x_122_);
lean_ctor_set(v___x_124_, 1, v___x_123_);
v___x_125_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__11));
v___x_126_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_126_, 0, v___x_124_);
lean_ctor_set(v___x_126_, 1, v___x_125_);
v___x_127_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_127_, 0, v___x_126_);
lean_ctor_set(v___x_127_, 1, v___x_112_);
v___x_128_ = l_BitVec_repr(v_w_105_, v_max_108_);
v___x_129_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_129_, 0, v___x_114_);
lean_ctor_set(v___x_129_, 1, v___x_128_);
v___x_130_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_130_, 0, v___x_129_);
lean_ctor_set_uint8(v___x_130_, sizeof(void*)*1, v___x_118_);
v___x_131_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_131_, 0, v___x_127_);
lean_ctor_set(v___x_131_, 1, v___x_130_);
v___x_132_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14);
v___x_133_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15));
v___x_134_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_134_, 0, v___x_133_);
lean_ctor_set(v___x_134_, 1, v___x_131_);
v___x_135_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16));
v___x_136_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_136_, 0, v___x_134_);
lean_ctor_set(v___x_136_, 1, v___x_135_);
v___x_137_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_137_, 0, v___x_132_);
lean_ctor_set(v___x_137_, 1, v___x_136_);
v___x_138_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_138_, 0, v___x_137_);
lean_ctor_set_uint8(v___x_138_, sizeof(void*)*1, v___x_118_);
return v___x_138_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr(lean_object* v_w_141_, lean_object* v_x_142_, lean_object* v_prec_143_){
_start:
{
lean_object* v___x_144_; 
v___x_144_ = lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(v_w_141_, v_x_142_);
return v___x_144_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval_repr___boxed(lean_object* v_w_145_, lean_object* v_x_146_, lean_object* v_prec_147_){
_start:
{
lean_object* v_res_148_; 
v_res_148_ = lp_parametric_PLDIProofs_instReprUInterval_repr(v_w_145_, v_x_146_, v_prec_147_);
lean_dec(v_prec_147_);
return v_res_148_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprUInterval(lean_object* v_w_149_){
_start:
{
lean_object* v___x_150_; 
v___x_150_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_instReprUInterval_repr___boxed), 3, 1);
lean_closure_set(v___x_150_, 0, v_w_149_);
return v___x_150_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(lean_object* v_x_151_, lean_object* v_x_152_){
_start:
{
lean_object* v_smin_153_; lean_object* v_smax_154_; lean_object* v_smin_155_; lean_object* v_smax_156_; uint8_t v___x_157_; 
v_smin_153_ = lean_ctor_get(v_x_151_, 0);
v_smax_154_ = lean_ctor_get(v_x_151_, 1);
v_smin_155_ = lean_ctor_get(v_x_152_, 0);
v_smax_156_ = lean_ctor_get(v_x_152_, 1);
v___x_157_ = lean_nat_dec_eq(v_smin_153_, v_smin_155_);
if (v___x_157_ == 0)
{
return v___x_157_;
}
else
{
uint8_t v___x_158_; 
v___x_158_ = lean_nat_dec_eq(v_smax_154_, v_smax_156_);
return v___x_158_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg___boxed(lean_object* v_x_159_, lean_object* v_x_160_){
_start:
{
uint8_t v_res_161_; lean_object* v_r_162_; 
v_res_161_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_x_159_, v_x_160_);
lean_dec_ref(v_x_160_);
lean_dec_ref(v_x_159_);
v_r_162_ = lean_box(v_res_161_);
return v_r_162_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq(lean_object* v_w_163_, lean_object* v_x_164_, lean_object* v_x_165_){
_start:
{
uint8_t v___x_166_; 
v___x_166_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_x_164_, v_x_165_);
return v___x_166_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___boxed(lean_object* v_w_167_, lean_object* v_x_168_, lean_object* v_x_169_){
_start:
{
uint8_t v_res_170_; lean_object* v_r_171_; 
v_res_170_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq(v_w_167_, v_x_168_, v_x_169_);
lean_dec_ref(v_x_169_);
lean_dec_ref(v_x_168_);
lean_dec(v_w_167_);
v_r_171_ = lean_box(v_res_170_);
return v_r_171_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval___redArg(lean_object* v_x_172_, lean_object* v_x_173_){
_start:
{
uint8_t v___x_174_; 
v___x_174_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_x_172_, v_x_173_);
return v___x_174_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval___redArg___boxed(lean_object* v_x_175_, lean_object* v_x_176_){
_start:
{
uint8_t v_res_177_; lean_object* v_r_178_; 
v_res_177_ = lp_parametric_PLDIProofs_instDecidableEqSInterval___redArg(v_x_175_, v_x_176_);
lean_dec_ref(v_x_176_);
lean_dec_ref(v_x_175_);
v_r_178_ = lean_box(v_res_177_);
return v_r_178_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSInterval(lean_object* v_w_179_, lean_object* v_x_180_, lean_object* v_x_181_){
_start:
{
uint8_t v___x_182_; 
v___x_182_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_x_180_, v_x_181_);
return v___x_182_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSInterval___boxed(lean_object* v_w_183_, lean_object* v_x_184_, lean_object* v_x_185_){
_start:
{
uint8_t v_res_186_; lean_object* v_r_187_; 
v_res_186_ = lp_parametric_PLDIProofs_instDecidableEqSInterval(v_w_183_, v_x_184_, v_x_185_);
lean_dec_ref(v_x_185_);
lean_dec_ref(v_x_184_);
lean_dec(v_w_183_);
v_r_187_ = lean_box(v_res_186_);
return v_r_187_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4(void){
_start:
{
lean_object* v___x_197_; lean_object* v___x_198_; 
v___x_197_ = lean_unsigned_to_nat(8u);
v___x_198_ = lean_nat_to_int(v___x_197_);
return v___x_198_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___redArg(lean_object* v_w_202_, lean_object* v_x_203_){
_start:
{
lean_object* v_smin_204_; lean_object* v_smax_205_; lean_object* v___x_207_; uint8_t v_isShared_208_; uint8_t v_isSharedCheck_237_; 
v_smin_204_ = lean_ctor_get(v_x_203_, 0);
v_smax_205_ = lean_ctor_get(v_x_203_, 1);
v_isSharedCheck_237_ = !lean_is_exclusive(v_x_203_);
if (v_isSharedCheck_237_ == 0)
{
v___x_207_ = v_x_203_;
v_isShared_208_ = v_isSharedCheck_237_;
goto v_resetjp_206_;
}
else
{
lean_inc(v_smax_205_);
lean_inc(v_smin_204_);
lean_dec(v_x_203_);
v___x_207_ = lean_box(0);
v_isShared_208_ = v_isSharedCheck_237_;
goto v_resetjp_206_;
}
v_resetjp_206_:
{
lean_object* v___x_209_; lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_214_; 
v___x_209_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5));
v___x_210_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__3));
v___x_211_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4, &lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4_once, _init_lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4);
lean_inc(v_w_202_);
v___x_212_ = l_BitVec_repr(v_w_202_, v_smin_204_);
if (v_isShared_208_ == 0)
{
lean_ctor_set_tag(v___x_207_, 4);
lean_ctor_set(v___x_207_, 1, v___x_212_);
lean_ctor_set(v___x_207_, 0, v___x_211_);
v___x_214_ = v___x_207_;
goto v_reusejp_213_;
}
else
{
lean_object* v_reuseFailAlloc_236_; 
v_reuseFailAlloc_236_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_236_, 0, v___x_211_);
lean_ctor_set(v_reuseFailAlloc_236_, 1, v___x_212_);
v___x_214_ = v_reuseFailAlloc_236_;
goto v_reusejp_213_;
}
v_reusejp_213_:
{
uint8_t v___x_215_; lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v___x_219_; lean_object* v___x_220_; lean_object* v___x_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___x_224_; lean_object* v___x_225_; lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v___x_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; lean_object* v___x_235_; 
v___x_215_ = 0;
v___x_216_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_216_, 0, v___x_214_);
lean_ctor_set_uint8(v___x_216_, sizeof(void*)*1, v___x_215_);
v___x_217_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_217_, 0, v___x_210_);
lean_ctor_set(v___x_217_, 1, v___x_216_);
v___x_218_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9));
v___x_219_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_219_, 0, v___x_217_);
lean_ctor_set(v___x_219_, 1, v___x_218_);
v___x_220_ = lean_box(1);
v___x_221_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_221_, 0, v___x_219_);
lean_ctor_set(v___x_221_, 1, v___x_220_);
v___x_222_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__6));
v___x_223_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_223_, 0, v___x_221_);
lean_ctor_set(v___x_223_, 1, v___x_222_);
v___x_224_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_224_, 0, v___x_223_);
lean_ctor_set(v___x_224_, 1, v___x_209_);
v___x_225_ = l_BitVec_repr(v_w_202_, v_smax_205_);
v___x_226_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_226_, 0, v___x_211_);
lean_ctor_set(v___x_226_, 1, v___x_225_);
v___x_227_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_227_, 0, v___x_226_);
lean_ctor_set_uint8(v___x_227_, sizeof(void*)*1, v___x_215_);
v___x_228_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_228_, 0, v___x_224_);
lean_ctor_set(v___x_228_, 1, v___x_227_);
v___x_229_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14);
v___x_230_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15));
v___x_231_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_231_, 0, v___x_230_);
lean_ctor_set(v___x_231_, 1, v___x_228_);
v___x_232_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16));
v___x_233_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_233_, 0, v___x_231_);
lean_ctor_set(v___x_233_, 1, v___x_232_);
v___x_234_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_234_, 0, v___x_229_);
lean_ctor_set(v___x_234_, 1, v___x_233_);
v___x_235_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_235_, 0, v___x_234_);
lean_ctor_set_uint8(v___x_235_, sizeof(void*)*1, v___x_215_);
return v___x_235_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr(lean_object* v_w_238_, lean_object* v_x_239_, lean_object* v_prec_240_){
_start:
{
lean_object* v___x_241_; 
v___x_241_ = lp_parametric_PLDIProofs_instReprSInterval_repr___redArg(v_w_238_, v_x_239_);
return v___x_241_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval_repr___boxed(lean_object* v_w_242_, lean_object* v_x_243_, lean_object* v_prec_244_){
_start:
{
lean_object* v_res_245_; 
v_res_245_ = lp_parametric_PLDIProofs_instReprSInterval_repr(v_w_242_, v_x_243_, v_prec_244_);
lean_dec(v_prec_244_);
return v_res_245_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSInterval(lean_object* v_w_246_){
_start:
{
lean_object* v___x_247_; 
v___x_247_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_instReprSInterval_repr___boxed), 3, 1);
lean_closure_set(v___x_247_, 0, v_w_246_);
return v___x_247_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(lean_object* v_x_248_, lean_object* v_x_249_){
_start:
{
lean_object* v_v_250_; lean_object* v_m_251_; lean_object* v_v_252_; lean_object* v_m_253_; uint8_t v___x_254_; 
v_v_250_ = lean_ctor_get(v_x_248_, 0);
v_m_251_ = lean_ctor_get(v_x_248_, 1);
v_v_252_ = lean_ctor_get(v_x_249_, 0);
v_m_253_ = lean_ctor_get(v_x_249_, 1);
v___x_254_ = lean_nat_dec_eq(v_v_250_, v_v_252_);
if (v___x_254_ == 0)
{
return v___x_254_;
}
else
{
uint8_t v___x_255_; 
v___x_255_ = lean_nat_dec_eq(v_m_251_, v_m_253_);
return v___x_255_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg___boxed(lean_object* v_x_256_, lean_object* v_x_257_){
_start:
{
uint8_t v_res_258_; lean_object* v_r_259_; 
v_res_258_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(v_x_256_, v_x_257_);
lean_dec_ref(v_x_257_);
lean_dec_ref(v_x_256_);
v_r_259_ = lean_box(v_res_258_);
return v_r_259_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum_decEq(lean_object* v_w_260_, lean_object* v_x_261_, lean_object* v_x_262_){
_start:
{
uint8_t v___x_263_; 
v___x_263_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(v_x_261_, v_x_262_);
return v___x_263_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___boxed(lean_object* v_w_264_, lean_object* v_x_265_, lean_object* v_x_266_){
_start:
{
uint8_t v_res_267_; lean_object* v_r_268_; 
v_res_267_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq(v_w_264_, v_x_265_, v_x_266_);
lean_dec_ref(v_x_266_);
lean_dec_ref(v_x_265_);
lean_dec(v_w_264_);
v_r_268_ = lean_box(v_res_267_);
return v_r_268_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum___redArg(lean_object* v_x_269_, lean_object* v_x_270_){
_start:
{
uint8_t v___x_271_; 
v___x_271_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(v_x_269_, v_x_270_);
return v___x_271_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum___redArg___boxed(lean_object* v_x_272_, lean_object* v_x_273_){
_start:
{
uint8_t v_res_274_; lean_object* v_r_275_; 
v_res_274_ = lp_parametric_PLDIProofs_instDecidableEqTnum___redArg(v_x_272_, v_x_273_);
lean_dec_ref(v_x_273_);
lean_dec_ref(v_x_272_);
v_r_275_ = lean_box(v_res_274_);
return v_r_275_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqTnum(lean_object* v_w_276_, lean_object* v_x_277_, lean_object* v_x_278_){
_start:
{
uint8_t v___x_279_; 
v___x_279_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(v_x_277_, v_x_278_);
return v___x_279_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqTnum___boxed(lean_object* v_w_280_, lean_object* v_x_281_, lean_object* v_x_282_){
_start:
{
uint8_t v_res_283_; lean_object* v_r_284_; 
v_res_283_ = lp_parametric_PLDIProofs_instDecidableEqTnum(v_w_280_, v_x_281_, v_x_282_);
lean_dec_ref(v_x_282_);
lean_dec_ref(v_x_281_);
lean_dec(v_w_280_);
v_r_284_ = lean_box(v_res_283_);
return v_r_284_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4(void){
_start:
{
lean_object* v___x_294_; lean_object* v___x_295_; 
v___x_294_ = lean_unsigned_to_nat(5u);
v___x_295_ = lean_nat_to_int(v___x_294_);
return v___x_295_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___redArg(lean_object* v_w_299_, lean_object* v_x_300_){
_start:
{
lean_object* v_v_301_; lean_object* v_m_302_; lean_object* v___x_304_; uint8_t v_isShared_305_; uint8_t v_isSharedCheck_334_; 
v_v_301_ = lean_ctor_get(v_x_300_, 0);
v_m_302_ = lean_ctor_get(v_x_300_, 1);
v_isSharedCheck_334_ = !lean_is_exclusive(v_x_300_);
if (v_isSharedCheck_334_ == 0)
{
v___x_304_ = v_x_300_;
v_isShared_305_ = v_isSharedCheck_334_;
goto v_resetjp_303_;
}
else
{
lean_inc(v_m_302_);
lean_inc(v_v_301_);
lean_dec(v_x_300_);
v___x_304_ = lean_box(0);
v_isShared_305_ = v_isSharedCheck_334_;
goto v_resetjp_303_;
}
v_resetjp_303_:
{
lean_object* v___x_306_; lean_object* v___x_307_; lean_object* v___x_308_; lean_object* v___x_309_; lean_object* v___x_311_; 
v___x_306_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5));
v___x_307_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__3));
v___x_308_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4, &lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4_once, _init_lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__4);
lean_inc(v_w_299_);
v___x_309_ = l_BitVec_repr(v_w_299_, v_v_301_);
if (v_isShared_305_ == 0)
{
lean_ctor_set_tag(v___x_304_, 4);
lean_ctor_set(v___x_304_, 1, v___x_309_);
lean_ctor_set(v___x_304_, 0, v___x_308_);
v___x_311_ = v___x_304_;
goto v_reusejp_310_;
}
else
{
lean_object* v_reuseFailAlloc_333_; 
v_reuseFailAlloc_333_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_333_, 0, v___x_308_);
lean_ctor_set(v_reuseFailAlloc_333_, 1, v___x_309_);
v___x_311_ = v_reuseFailAlloc_333_;
goto v_reusejp_310_;
}
v_reusejp_310_:
{
uint8_t v___x_312_; lean_object* v___x_313_; lean_object* v___x_314_; lean_object* v___x_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v___x_318_; lean_object* v___x_319_; lean_object* v___x_320_; lean_object* v___x_321_; lean_object* v___x_322_; lean_object* v___x_323_; lean_object* v___x_324_; lean_object* v___x_325_; lean_object* v___x_326_; lean_object* v___x_327_; lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; lean_object* v___x_331_; lean_object* v___x_332_; 
v___x_312_ = 0;
v___x_313_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_313_, 0, v___x_311_);
lean_ctor_set_uint8(v___x_313_, sizeof(void*)*1, v___x_312_);
v___x_314_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_314_, 0, v___x_307_);
lean_ctor_set(v___x_314_, 1, v___x_313_);
v___x_315_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9));
v___x_316_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_316_, 0, v___x_314_);
lean_ctor_set(v___x_316_, 1, v___x_315_);
v___x_317_ = lean_box(1);
v___x_318_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_318_, 0, v___x_316_);
lean_ctor_set(v___x_318_, 1, v___x_317_);
v___x_319_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprTnum_repr___redArg___closed__6));
v___x_320_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_320_, 0, v___x_318_);
lean_ctor_set(v___x_320_, 1, v___x_319_);
v___x_321_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_321_, 0, v___x_320_);
lean_ctor_set(v___x_321_, 1, v___x_306_);
v___x_322_ = l_BitVec_repr(v_w_299_, v_m_302_);
v___x_323_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_323_, 0, v___x_308_);
lean_ctor_set(v___x_323_, 1, v___x_322_);
v___x_324_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_324_, 0, v___x_323_);
lean_ctor_set_uint8(v___x_324_, sizeof(void*)*1, v___x_312_);
v___x_325_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_325_, 0, v___x_321_);
lean_ctor_set(v___x_325_, 1, v___x_324_);
v___x_326_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14);
v___x_327_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15));
v___x_328_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_328_, 0, v___x_327_);
lean_ctor_set(v___x_328_, 1, v___x_325_);
v___x_329_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16));
v___x_330_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_330_, 0, v___x_328_);
lean_ctor_set(v___x_330_, 1, v___x_329_);
v___x_331_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_331_, 0, v___x_326_);
lean_ctor_set(v___x_331_, 1, v___x_330_);
v___x_332_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_332_, 0, v___x_331_);
lean_ctor_set_uint8(v___x_332_, sizeof(void*)*1, v___x_312_);
return v___x_332_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr(lean_object* v_w_335_, lean_object* v_x_336_, lean_object* v_prec_337_){
_start:
{
lean_object* v___x_338_; 
v___x_338_ = lp_parametric_PLDIProofs_instReprTnum_repr___redArg(v_w_335_, v_x_336_);
return v___x_338_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum_repr___boxed(lean_object* v_w_339_, lean_object* v_x_340_, lean_object* v_prec_341_){
_start:
{
lean_object* v_res_342_; 
v_res_342_ = lp_parametric_PLDIProofs_instReprTnum_repr(v_w_339_, v_x_340_, v_prec_341_);
lean_dec(v_prec_341_);
return v_res_342_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprTnum(lean_object* v_w_343_){
_start:
{
lean_object* v___x_344_; 
v___x_344_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_instReprTnum_repr___boxed), 3, 1);
lean_closure_set(v___x_344_, 0, v_w_343_);
return v___x_344_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf___redArg(lean_object* v_I_345_){
_start:
{
lean_object* v_min_346_; lean_object* v_max_347_; uint8_t v___x_348_; 
v_min_346_ = lean_ctor_get(v_I_345_, 0);
v_max_347_ = lean_ctor_get(v_I_345_, 1);
v___x_348_ = lean_nat_dec_le(v_min_346_, v_max_347_);
return v___x_348_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf___redArg___boxed(lean_object* v_I_349_){
_start:
{
uint8_t v_res_350_; lean_object* v_r_351_; 
v_res_350_ = lp_parametric_PLDIProofs_instDecidableWf___redArg(v_I_349_);
lean_dec_ref(v_I_349_);
v_r_351_ = lean_box(v_res_350_);
return v_r_351_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf(lean_object* v_w_352_, lean_object* v_I_353_){
_start:
{
uint8_t v___x_354_; 
v___x_354_ = lp_parametric_PLDIProofs_instDecidableWf___redArg(v_I_353_);
return v___x_354_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf___boxed(lean_object* v_w_355_, lean_object* v_I_356_){
_start:
{
uint8_t v_res_357_; lean_object* v_r_358_; 
v_res_357_ = lp_parametric_PLDIProofs_instDecidableWf(v_w_355_, v_I_356_);
lean_dec_ref(v_I_356_);
lean_dec(v_w_355_);
v_r_358_ = lean_box(v_res_357_);
return v_r_358_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf__1(lean_object* v_w_359_, lean_object* v_I_360_){
_start:
{
lean_object* v_smin_361_; lean_object* v_smax_362_; uint8_t v___x_363_; 
v_smin_361_ = lean_ctor_get(v_I_360_, 0);
lean_inc(v_smin_361_);
v_smax_362_ = lean_ctor_get(v_I_360_, 1);
lean_inc(v_smax_362_);
lean_dec_ref(v_I_360_);
v___x_363_ = l_BitVec_sle(v_w_359_, v_smin_361_, v_smax_362_);
return v___x_363_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf__1___boxed(lean_object* v_w_364_, lean_object* v_I_365_){
_start:
{
uint8_t v_res_366_; lean_object* v_r_367_; 
v_res_366_ = lp_parametric_PLDIProofs_instDecidableWf__1(v_w_364_, v_I_365_);
lean_dec(v_w_364_);
v_r_367_ = lean_box(v_res_366_);
return v_r_367_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWf__2(lean_object* v_w_368_, lean_object* v_t_369_){
_start:
{
lean_object* v_v_370_; lean_object* v_m_371_; lean_object* v___x_372_; lean_object* v___x_373_; lean_object* v___x_374_; uint8_t v___x_375_; 
v_v_370_ = lean_ctor_get(v_t_369_, 0);
v_m_371_ = lean_ctor_get(v_t_369_, 1);
v___x_372_ = lean_nat_land(v_v_370_, v_m_371_);
v___x_373_ = lean_unsigned_to_nat(0u);
v___x_374_ = l_BitVec_ofNat(v_w_368_, v___x_373_);
v___x_375_ = lean_nat_dec_eq(v___x_372_, v___x_374_);
lean_dec(v___x_374_);
lean_dec(v___x_372_);
return v___x_375_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWf__2___boxed(lean_object* v_w_376_, lean_object* v_t_377_){
_start:
{
uint8_t v_res_378_; lean_object* v_r_379_; 
v_res_378_ = lp_parametric_PLDIProofs_instDecidableWf__2(v_w_376_, v_t_377_);
lean_dec_ref(v_t_377_);
lean_dec(v_w_376_);
v_r_379_ = lean_box(v_res_378_);
return v_r_379_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaU___redArg(lean_object* v_I_380_, lean_object* v_x_381_){
_start:
{
lean_object* v_min_382_; lean_object* v_max_383_; uint8_t v___x_384_; 
v_min_382_ = lean_ctor_get(v_I_380_, 0);
v_max_383_ = lean_ctor_get(v_I_380_, 1);
v___x_384_ = lean_nat_dec_le(v_min_382_, v_x_381_);
if (v___x_384_ == 0)
{
return v___x_384_;
}
else
{
uint8_t v___x_385_; 
v___x_385_ = lean_nat_dec_le(v_x_381_, v_max_383_);
return v___x_385_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaU___redArg___boxed(lean_object* v_I_386_, lean_object* v_x_387_){
_start:
{
uint8_t v_res_388_; lean_object* v_r_389_; 
v_res_388_ = lp_parametric_PLDIProofs_instDecidableGammaU___redArg(v_I_386_, v_x_387_);
lean_dec(v_x_387_);
lean_dec_ref(v_I_386_);
v_r_389_ = lean_box(v_res_388_);
return v_r_389_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaU(lean_object* v_w_390_, lean_object* v_I_391_, lean_object* v_x_392_){
_start:
{
uint8_t v___x_393_; 
v___x_393_ = lp_parametric_PLDIProofs_instDecidableGammaU___redArg(v_I_391_, v_x_392_);
return v___x_393_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaU___boxed(lean_object* v_w_394_, lean_object* v_I_395_, lean_object* v_x_396_){
_start:
{
uint8_t v_res_397_; lean_object* v_r_398_; 
v_res_397_ = lp_parametric_PLDIProofs_instDecidableGammaU(v_w_394_, v_I_395_, v_x_396_);
lean_dec(v_x_396_);
lean_dec_ref(v_I_395_);
lean_dec(v_w_394_);
v_r_398_ = lean_box(v_res_397_);
return v_r_398_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaS(lean_object* v_w_399_, lean_object* v_I_400_, lean_object* v_x_401_){
_start:
{
lean_object* v_smin_402_; lean_object* v_smax_403_; uint8_t v___x_404_; 
v_smin_402_ = lean_ctor_get(v_I_400_, 0);
lean_inc(v_smin_402_);
v_smax_403_ = lean_ctor_get(v_I_400_, 1);
lean_inc(v_smax_403_);
lean_dec_ref(v_I_400_);
lean_inc(v_x_401_);
v___x_404_ = l_BitVec_sle(v_w_399_, v_smin_402_, v_x_401_);
if (v___x_404_ == 0)
{
lean_dec(v_smax_403_);
lean_dec(v_x_401_);
return v___x_404_;
}
else
{
uint8_t v___x_405_; 
v___x_405_ = l_BitVec_sle(v_w_399_, v_x_401_, v_smax_403_);
return v___x_405_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaS___boxed(lean_object* v_w_406_, lean_object* v_I_407_, lean_object* v_x_408_){
_start:
{
uint8_t v_res_409_; lean_object* v_r_410_; 
v_res_409_ = lp_parametric_PLDIProofs_instDecidableGammaS(v_w_406_, v_I_407_, v_x_408_);
lean_dec(v_w_406_);
v_r_410_ = lean_box(v_res_409_);
return v_r_410_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaTnum(lean_object* v_w_411_, lean_object* v_t_412_, lean_object* v_x_413_){
_start:
{
lean_object* v_v_414_; lean_object* v_m_415_; lean_object* v___x_416_; lean_object* v___x_417_; uint8_t v___x_418_; 
v_v_414_ = lean_ctor_get(v_t_412_, 0);
v_m_415_ = lean_ctor_get(v_t_412_, 1);
v___x_416_ = l_BitVec_not(v_w_411_, v_m_415_);
v___x_417_ = lean_nat_land(v_x_413_, v___x_416_);
lean_dec(v___x_416_);
v___x_418_ = lean_nat_dec_eq(v___x_417_, v_v_414_);
lean_dec(v___x_417_);
return v___x_418_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaTnum___boxed(lean_object* v_w_419_, lean_object* v_t_420_, lean_object* v_x_421_){
_start:
{
uint8_t v_res_422_; lean_object* v_r_423_; 
v_res_422_ = lp_parametric_PLDIProofs_instDecidableGammaTnum(v_w_419_, v_t_420_, v_x_421_);
lean_dec(v_x_421_);
lean_dec_ref(v_t_420_);
lean_dec(v_w_419_);
v_r_423_ = lean_box(v_res_422_);
return v_r_423_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg(lean_object* v_w__lo_424_, lean_object* v_I_425_, lean_object* v_x_426_){
_start:
{
lean_object* v___x_427_; uint8_t v___x_428_; 
v___x_427_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_424_, v_x_426_);
v___x_428_ = lp_parametric_PLDIProofs_instDecidableGammaU___redArg(v_I_425_, v___x_427_);
lean_dec(v___x_427_);
return v___x_428_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg___boxed(lean_object* v_w__lo_429_, lean_object* v_I_430_, lean_object* v_x_431_){
_start:
{
uint8_t v_res_432_; lean_object* v_r_433_; 
v_res_432_ = lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg(v_w__lo_429_, v_I_430_, v_x_431_);
lean_dec(v_x_431_);
lean_dec_ref(v_I_430_);
lean_dec(v_w__lo_429_);
v_r_433_ = lean_box(v_res_432_);
return v_r_433_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaUSub(lean_object* v_w__lo_434_, lean_object* v_w__hi_435_, lean_object* v_I_436_, lean_object* v_x_437_){
_start:
{
uint8_t v___x_438_; 
v___x_438_ = lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg(v_w__lo_434_, v_I_436_, v_x_437_);
return v___x_438_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaUSub___boxed(lean_object* v_w__lo_439_, lean_object* v_w__hi_440_, lean_object* v_I_441_, lean_object* v_x_442_){
_start:
{
uint8_t v_res_443_; lean_object* v_r_444_; 
v_res_443_ = lp_parametric_PLDIProofs_instDecidableGammaUSub(v_w__lo_439_, v_w__hi_440_, v_I_441_, v_x_442_);
lean_dec(v_x_442_);
lean_dec_ref(v_I_441_);
lean_dec(v_w__hi_440_);
lean_dec(v_w__lo_439_);
v_r_444_ = lean_box(v_res_443_);
return v_r_444_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg(lean_object* v_w__lo_445_, lean_object* v_I_446_, lean_object* v_x_447_){
_start:
{
lean_object* v___x_448_; uint8_t v___x_449_; 
v___x_448_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_445_, v_x_447_);
v___x_449_ = lp_parametric_PLDIProofs_instDecidableGammaS(v_w__lo_445_, v_I_446_, v___x_448_);
return v___x_449_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg___boxed(lean_object* v_w__lo_450_, lean_object* v_I_451_, lean_object* v_x_452_){
_start:
{
uint8_t v_res_453_; lean_object* v_r_454_; 
v_res_453_ = lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg(v_w__lo_450_, v_I_451_, v_x_452_);
lean_dec(v_x_452_);
lean_dec(v_w__lo_450_);
v_r_454_ = lean_box(v_res_453_);
return v_r_454_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaSSub(lean_object* v_w__lo_455_, lean_object* v_w__hi_456_, lean_object* v_I_457_, lean_object* v_x_458_){
_start:
{
uint8_t v___x_459_; 
v___x_459_ = lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg(v_w__lo_455_, v_I_457_, v_x_458_);
return v___x_459_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaSSub___boxed(lean_object* v_w__lo_460_, lean_object* v_w__hi_461_, lean_object* v_I_462_, lean_object* v_x_463_){
_start:
{
uint8_t v_res_464_; lean_object* v_r_465_; 
v_res_464_ = lp_parametric_PLDIProofs_instDecidableGammaSSub(v_w__lo_460_, v_w__hi_461_, v_I_462_, v_x_463_);
lean_dec(v_x_463_);
lean_dec(v_w__hi_461_);
lean_dec(v_w__lo_460_);
v_r_465_ = lean_box(v_res_464_);
return v_r_465_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(lean_object* v_x_466_, lean_object* v_x_467_){
_start:
{
lean_object* v_u64_468_; lean_object* v_s64_469_; lean_object* v_u32_470_; lean_object* v_s32_471_; lean_object* v_tnum_472_; lean_object* v_u64_473_; lean_object* v_s64_474_; lean_object* v_u32_475_; lean_object* v_s32_476_; lean_object* v_tnum_477_; uint8_t v___x_478_; 
v_u64_468_ = lean_ctor_get(v_x_466_, 0);
v_s64_469_ = lean_ctor_get(v_x_466_, 1);
v_u32_470_ = lean_ctor_get(v_x_466_, 2);
v_s32_471_ = lean_ctor_get(v_x_466_, 3);
v_tnum_472_ = lean_ctor_get(v_x_466_, 4);
v_u64_473_ = lean_ctor_get(v_x_467_, 0);
v_s64_474_ = lean_ctor_get(v_x_467_, 1);
v_u32_475_ = lean_ctor_get(v_x_467_, 2);
v_s32_476_ = lean_ctor_get(v_x_467_, 3);
v_tnum_477_ = lean_ctor_get(v_x_467_, 4);
v___x_478_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_u64_468_, v_u64_473_);
if (v___x_478_ == 0)
{
return v___x_478_;
}
else
{
uint8_t v___x_479_; 
v___x_479_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_s64_469_, v_s64_474_);
if (v___x_479_ == 0)
{
return v___x_479_;
}
else
{
uint8_t v___x_480_; 
v___x_480_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_u32_470_, v_u32_475_);
if (v___x_480_ == 0)
{
return v___x_480_;
}
else
{
uint8_t v___x_481_; 
v___x_481_ = lp_parametric_PLDIProofs_instDecidableEqSInterval_decEq___redArg(v_s32_471_, v_s32_476_);
if (v___x_481_ == 0)
{
return v___x_481_;
}
else
{
uint8_t v___x_482_; 
v___x_482_ = lp_parametric_PLDIProofs_instDecidableEqTnum_decEq___redArg(v_tnum_472_, v_tnum_477_);
return v___x_482_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg___boxed(lean_object* v_x_483_, lean_object* v_x_484_){
_start:
{
uint8_t v_res_485_; lean_object* v_r_486_; 
v_res_485_ = lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(v_x_483_, v_x_484_);
lean_dec_ref(v_x_484_);
lean_dec_ref(v_x_483_);
v_r_486_ = lean_box(v_res_485_);
return v_r_486_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState_decEq(lean_object* v_w__lo_487_, lean_object* v_w__hi_488_, lean_object* v_x_489_, lean_object* v_x_490_){
_start:
{
uint8_t v___x_491_; 
v___x_491_ = lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(v_x_489_, v_x_490_);
return v___x_491_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___boxed(lean_object* v_w__lo_492_, lean_object* v_w__hi_493_, lean_object* v_x_494_, lean_object* v_x_495_){
_start:
{
uint8_t v_res_496_; lean_object* v_r_497_; 
v_res_496_ = lp_parametric_PLDIProofs_instDecidableEqRegState_decEq(v_w__lo_492_, v_w__hi_493_, v_x_494_, v_x_495_);
lean_dec_ref(v_x_495_);
lean_dec_ref(v_x_494_);
lean_dec(v_w__hi_493_);
lean_dec(v_w__lo_492_);
v_r_497_ = lean_box(v_res_496_);
return v_r_497_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState___redArg(lean_object* v_x_498_, lean_object* v_x_499_){
_start:
{
uint8_t v___x_500_; 
v___x_500_ = lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(v_x_498_, v_x_499_);
return v___x_500_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState___redArg___boxed(lean_object* v_x_501_, lean_object* v_x_502_){
_start:
{
uint8_t v_res_503_; lean_object* v_r_504_; 
v_res_503_ = lp_parametric_PLDIProofs_instDecidableEqRegState___redArg(v_x_501_, v_x_502_);
lean_dec_ref(v_x_502_);
lean_dec_ref(v_x_501_);
v_r_504_ = lean_box(v_res_503_);
return v_r_504_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqRegState(lean_object* v_w__lo_505_, lean_object* v_w__hi_506_, lean_object* v_x_507_, lean_object* v_x_508_){
_start:
{
uint8_t v___x_509_; 
v___x_509_ = lp_parametric_PLDIProofs_instDecidableEqRegState_decEq___redArg(v_x_507_, v_x_508_);
return v___x_509_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqRegState___boxed(lean_object* v_w__lo_510_, lean_object* v_w__hi_511_, lean_object* v_x_512_, lean_object* v_x_513_){
_start:
{
uint8_t v_res_514_; lean_object* v_r_515_; 
v_res_514_ = lp_parametric_PLDIProofs_instDecidableEqRegState(v_w__lo_510_, v_w__hi_511_, v_x_512_, v_x_513_);
lean_dec_ref(v_x_513_);
lean_dec_ref(v_x_512_);
lean_dec(v_w__hi_511_);
lean_dec(v_w__lo_510_);
v_r_515_ = lean_box(v_res_514_);
return v_r_515_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg(lean_object* v_w__lo_537_, lean_object* v_w__hi_538_, lean_object* v_x_539_){
_start:
{
lean_object* v_u64_540_; lean_object* v_s64_541_; lean_object* v_u32_542_; lean_object* v_s32_543_; lean_object* v_tnum_544_; lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; lean_object* v___x_548_; lean_object* v___x_549_; lean_object* v___x_550_; uint8_t v___x_551_; lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; lean_object* v___x_560_; lean_object* v___x_561_; lean_object* v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; lean_object* v___x_565_; lean_object* v___x_566_; lean_object* v___x_567_; lean_object* v___x_568_; lean_object* v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; lean_object* v___x_572_; lean_object* v___x_573_; lean_object* v___x_574_; lean_object* v___x_575_; lean_object* v___x_576_; lean_object* v___x_577_; lean_object* v___x_578_; lean_object* v___x_579_; lean_object* v___x_580_; lean_object* v___x_581_; lean_object* v___x_582_; lean_object* v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; lean_object* v___x_587_; lean_object* v___x_588_; lean_object* v___x_589_; lean_object* v___x_590_; lean_object* v___x_591_; lean_object* v___x_592_; lean_object* v___x_593_; lean_object* v___x_594_; lean_object* v___x_595_; lean_object* v___x_596_; lean_object* v___x_597_; lean_object* v___x_598_; lean_object* v___x_599_; 
v_u64_540_ = lean_ctor_get(v_x_539_, 0);
lean_inc_ref(v_u64_540_);
v_s64_541_ = lean_ctor_get(v_x_539_, 1);
lean_inc_ref(v_s64_541_);
v_u32_542_ = lean_ctor_get(v_x_539_, 2);
lean_inc_ref(v_u32_542_);
v_s32_543_ = lean_ctor_get(v_x_539_, 3);
lean_inc_ref(v_s32_543_);
v_tnum_544_ = lean_ctor_get(v_x_539_, 4);
lean_inc_ref(v_tnum_544_);
lean_dec_ref(v_x_539_);
v___x_545_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5));
v___x_546_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__3));
v___x_547_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__7);
v___x_548_ = lean_nat_add(v_w__lo_537_, v_w__hi_538_);
lean_inc_n(v___x_548_, 2);
v___x_549_ = lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(v___x_548_, v_u64_540_);
v___x_550_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_550_, 0, v___x_547_);
lean_ctor_set(v___x_550_, 1, v___x_549_);
v___x_551_ = 0;
v___x_552_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_552_, 0, v___x_550_);
lean_ctor_set_uint8(v___x_552_, sizeof(void*)*1, v___x_551_);
v___x_553_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_553_, 0, v___x_546_);
lean_ctor_set(v___x_553_, 1, v___x_552_);
v___x_554_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9));
v___x_555_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_555_, 0, v___x_553_);
lean_ctor_set(v___x_555_, 1, v___x_554_);
v___x_556_ = lean_box(1);
v___x_557_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_557_, 0, v___x_555_);
lean_ctor_set(v___x_557_, 1, v___x_556_);
v___x_558_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__5));
v___x_559_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_559_, 0, v___x_557_);
lean_ctor_set(v___x_559_, 1, v___x_558_);
v___x_560_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_560_, 0, v___x_559_);
lean_ctor_set(v___x_560_, 1, v___x_545_);
v___x_561_ = lp_parametric_PLDIProofs_instReprSInterval_repr___redArg(v___x_548_, v_s64_541_);
v___x_562_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_562_, 0, v___x_547_);
lean_ctor_set(v___x_562_, 1, v___x_561_);
v___x_563_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_563_, 0, v___x_562_);
lean_ctor_set_uint8(v___x_563_, sizeof(void*)*1, v___x_551_);
v___x_564_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_564_, 0, v___x_560_);
lean_ctor_set(v___x_564_, 1, v___x_563_);
v___x_565_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_565_, 0, v___x_564_);
lean_ctor_set(v___x_565_, 1, v___x_554_);
v___x_566_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_566_, 0, v___x_565_);
lean_ctor_set(v___x_566_, 1, v___x_556_);
v___x_567_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__7));
v___x_568_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_568_, 0, v___x_566_);
lean_ctor_set(v___x_568_, 1, v___x_567_);
v___x_569_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_569_, 0, v___x_568_);
lean_ctor_set(v___x_569_, 1, v___x_545_);
lean_inc(v_w__lo_537_);
v___x_570_ = lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(v_w__lo_537_, v_u32_542_);
v___x_571_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_571_, 0, v___x_547_);
lean_ctor_set(v___x_571_, 1, v___x_570_);
v___x_572_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_572_, 0, v___x_571_);
lean_ctor_set_uint8(v___x_572_, sizeof(void*)*1, v___x_551_);
v___x_573_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_573_, 0, v___x_569_);
lean_ctor_set(v___x_573_, 1, v___x_572_);
v___x_574_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_574_, 0, v___x_573_);
lean_ctor_set(v___x_574_, 1, v___x_554_);
v___x_575_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_575_, 0, v___x_574_);
lean_ctor_set(v___x_575_, 1, v___x_556_);
v___x_576_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__9));
v___x_577_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_577_, 0, v___x_575_);
lean_ctor_set(v___x_577_, 1, v___x_576_);
v___x_578_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_578_, 0, v___x_577_);
lean_ctor_set(v___x_578_, 1, v___x_545_);
v___x_579_ = lp_parametric_PLDIProofs_instReprSInterval_repr___redArg(v_w__lo_537_, v_s32_543_);
v___x_580_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_580_, 0, v___x_547_);
lean_ctor_set(v___x_580_, 1, v___x_579_);
v___x_581_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_581_, 0, v___x_580_);
lean_ctor_set_uint8(v___x_581_, sizeof(void*)*1, v___x_551_);
v___x_582_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_582_, 0, v___x_578_);
lean_ctor_set(v___x_582_, 1, v___x_581_);
v___x_583_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_583_, 0, v___x_582_);
lean_ctor_set(v___x_583_, 1, v___x_554_);
v___x_584_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_584_, 0, v___x_583_);
lean_ctor_set(v___x_584_, 1, v___x_556_);
v___x_585_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprRegState_repr___redArg___closed__11));
v___x_586_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_586_, 0, v___x_584_);
lean_ctor_set(v___x_586_, 1, v___x_585_);
v___x_587_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_587_, 0, v___x_586_);
lean_ctor_set(v___x_587_, 1, v___x_545_);
v___x_588_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4, &lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4_once, _init_lp_parametric_PLDIProofs_instReprSInterval_repr___redArg___closed__4);
v___x_589_ = lp_parametric_PLDIProofs_instReprTnum_repr___redArg(v___x_548_, v_tnum_544_);
v___x_590_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_590_, 0, v___x_588_);
lean_ctor_set(v___x_590_, 1, v___x_589_);
v___x_591_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_591_, 0, v___x_590_);
lean_ctor_set_uint8(v___x_591_, sizeof(void*)*1, v___x_551_);
v___x_592_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_592_, 0, v___x_587_);
lean_ctor_set(v___x_592_, 1, v___x_591_);
v___x_593_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14);
v___x_594_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15));
v___x_595_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_595_, 0, v___x_594_);
lean_ctor_set(v___x_595_, 1, v___x_592_);
v___x_596_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16));
v___x_597_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_597_, 0, v___x_595_);
lean_ctor_set(v___x_597_, 1, v___x_596_);
v___x_598_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_598_, 0, v___x_593_);
lean_ctor_set(v___x_598_, 1, v___x_597_);
v___x_599_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_599_, 0, v___x_598_);
lean_ctor_set_uint8(v___x_599_, sizeof(void*)*1, v___x_551_);
return v___x_599_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___redArg___boxed(lean_object* v_w__lo_600_, lean_object* v_w__hi_601_, lean_object* v_x_602_){
_start:
{
lean_object* v_res_603_; 
v_res_603_ = lp_parametric_PLDIProofs_instReprRegState_repr___redArg(v_w__lo_600_, v_w__hi_601_, v_x_602_);
lean_dec(v_w__hi_601_);
return v_res_603_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr(lean_object* v_w__lo_604_, lean_object* v_w__hi_605_, lean_object* v_x_606_, lean_object* v_prec_607_){
_start:
{
lean_object* v___x_608_; 
v___x_608_ = lp_parametric_PLDIProofs_instReprRegState_repr___redArg(v_w__lo_604_, v_w__hi_605_, v_x_606_);
return v___x_608_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState_repr___boxed(lean_object* v_w__lo_609_, lean_object* v_w__hi_610_, lean_object* v_x_611_, lean_object* v_prec_612_){
_start:
{
lean_object* v_res_613_; 
v_res_613_ = lp_parametric_PLDIProofs_instReprRegState_repr(v_w__lo_609_, v_w__hi_610_, v_x_611_, v_prec_612_);
lean_dec(v_prec_612_);
lean_dec(v_w__hi_610_);
return v_res_613_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprRegState(lean_object* v_w__lo_614_, lean_object* v_w__hi_615_){
_start:
{
lean_object* v___x_616_; 
v___x_616_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_instReprRegState_repr___boxed), 4, 2);
lean_closure_set(v___x_616_, 0, v_w__lo_614_);
lean_closure_set(v___x_616_, 1, v_w__hi_615_);
return v___x_616_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableGammaReg(lean_object* v_w__lo_617_, lean_object* v_w__hi_618_, lean_object* v_r_619_, lean_object* v_x_620_){
_start:
{
lean_object* v_u64_621_; lean_object* v_s64_622_; lean_object* v_u32_623_; lean_object* v_s32_624_; lean_object* v_tnum_625_; uint8_t v___x_626_; 
v_u64_621_ = lean_ctor_get(v_r_619_, 0);
lean_inc_ref(v_u64_621_);
v_s64_622_ = lean_ctor_get(v_r_619_, 1);
lean_inc_ref(v_s64_622_);
v_u32_623_ = lean_ctor_get(v_r_619_, 2);
lean_inc_ref(v_u32_623_);
v_s32_624_ = lean_ctor_get(v_r_619_, 3);
lean_inc_ref(v_s32_624_);
v_tnum_625_ = lean_ctor_get(v_r_619_, 4);
lean_inc_ref(v_tnum_625_);
lean_dec_ref(v_r_619_);
v___x_626_ = lp_parametric_PLDIProofs_instDecidableGammaU___redArg(v_u64_621_, v_x_620_);
lean_dec_ref(v_u64_621_);
if (v___x_626_ == 0)
{
lean_dec_ref(v_tnum_625_);
lean_dec_ref(v_s32_624_);
lean_dec_ref(v_u32_623_);
lean_dec_ref(v_s64_622_);
lean_dec(v_x_620_);
return v___x_626_;
}
else
{
lean_object* v___x_627_; uint8_t v___x_628_; 
v___x_627_ = lean_nat_add(v_w__lo_617_, v_w__hi_618_);
lean_inc(v_x_620_);
v___x_628_ = lp_parametric_PLDIProofs_instDecidableGammaS(v___x_627_, v_s64_622_, v_x_620_);
if (v___x_628_ == 0)
{
lean_dec(v___x_627_);
lean_dec_ref(v_tnum_625_);
lean_dec_ref(v_s32_624_);
lean_dec_ref(v_u32_623_);
lean_dec(v_x_620_);
return v___x_628_;
}
else
{
uint8_t v___x_629_; 
v___x_629_ = lp_parametric_PLDIProofs_instDecidableGammaUSub___redArg(v_w__lo_617_, v_u32_623_, v_x_620_);
lean_dec_ref(v_u32_623_);
if (v___x_629_ == 0)
{
lean_dec(v___x_627_);
lean_dec_ref(v_tnum_625_);
lean_dec_ref(v_s32_624_);
lean_dec(v_x_620_);
return v___x_629_;
}
else
{
uint8_t v___x_630_; 
v___x_630_ = lp_parametric_PLDIProofs_instDecidableGammaSSub___redArg(v_w__lo_617_, v_s32_624_, v_x_620_);
if (v___x_630_ == 0)
{
lean_dec(v___x_627_);
lean_dec_ref(v_tnum_625_);
lean_dec(v_x_620_);
return v___x_630_;
}
else
{
uint8_t v___x_631_; 
v___x_631_ = lp_parametric_PLDIProofs_instDecidableGammaTnum(v___x_627_, v_tnum_625_, v_x_620_);
lean_dec(v_x_620_);
lean_dec_ref(v_tnum_625_);
lean_dec(v___x_627_);
return v___x_631_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableGammaReg___boxed(lean_object* v_w__lo_632_, lean_object* v_w__hi_633_, lean_object* v_r_634_, lean_object* v_x_635_){
_start:
{
uint8_t v_res_636_; lean_object* v_r_637_; 
v_res_636_ = lp_parametric_PLDIProofs_instDecidableGammaReg(v_w__lo_632_, v_w__hi_633_, v_r_634_, v_x_635_);
lean_dec(v_w__hi_633_);
lean_dec(v_w__lo_632_);
v_r_637_ = lean_box(v_res_636_);
return v_r_637_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableWF(lean_object* v_w__lo_638_, lean_object* v_w__hi_639_, lean_object* v_r_640_){
_start:
{
lean_object* v_u64_641_; lean_object* v_s64_642_; lean_object* v_u32_643_; lean_object* v_s32_644_; lean_object* v_tnum_645_; uint8_t v___x_646_; 
v_u64_641_ = lean_ctor_get(v_r_640_, 0);
lean_inc_ref(v_u64_641_);
v_s64_642_ = lean_ctor_get(v_r_640_, 1);
lean_inc_ref(v_s64_642_);
v_u32_643_ = lean_ctor_get(v_r_640_, 2);
lean_inc_ref(v_u32_643_);
v_s32_644_ = lean_ctor_get(v_r_640_, 3);
lean_inc_ref(v_s32_644_);
v_tnum_645_ = lean_ctor_get(v_r_640_, 4);
lean_inc_ref(v_tnum_645_);
lean_dec_ref(v_r_640_);
v___x_646_ = lp_parametric_PLDIProofs_instDecidableWf___redArg(v_u64_641_);
lean_dec_ref(v_u64_641_);
if (v___x_646_ == 0)
{
lean_dec_ref(v_tnum_645_);
lean_dec_ref(v_s32_644_);
lean_dec_ref(v_u32_643_);
lean_dec_ref(v_s64_642_);
return v___x_646_;
}
else
{
lean_object* v___x_647_; uint8_t v___x_648_; 
v___x_647_ = lean_nat_add(v_w__lo_638_, v_w__hi_639_);
v___x_648_ = lp_parametric_PLDIProofs_instDecidableWf__1(v___x_647_, v_s64_642_);
if (v___x_648_ == 0)
{
lean_dec(v___x_647_);
lean_dec_ref(v_tnum_645_);
lean_dec_ref(v_s32_644_);
lean_dec_ref(v_u32_643_);
return v___x_648_;
}
else
{
uint8_t v___x_649_; 
v___x_649_ = lp_parametric_PLDIProofs_instDecidableWf___redArg(v_u32_643_);
lean_dec_ref(v_u32_643_);
if (v___x_649_ == 0)
{
lean_dec(v___x_647_);
lean_dec_ref(v_tnum_645_);
lean_dec_ref(v_s32_644_);
return v___x_649_;
}
else
{
uint8_t v___x_650_; 
v___x_650_ = lp_parametric_PLDIProofs_instDecidableWf__1(v_w__lo_638_, v_s32_644_);
if (v___x_650_ == 0)
{
lean_dec(v___x_647_);
lean_dec_ref(v_tnum_645_);
return v___x_650_;
}
else
{
uint8_t v___x_651_; 
v___x_651_ = lp_parametric_PLDIProofs_instDecidableWf__2(v___x_647_, v_tnum_645_);
lean_dec_ref(v_tnum_645_);
lean_dec(v___x_647_);
return v___x_651_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableWF___boxed(lean_object* v_w__lo_652_, lean_object* v_w__hi_653_, lean_object* v_r_654_){
_start:
{
uint8_t v_res_655_; lean_object* v_r_656_; 
v_res_655_ = lp_parametric_PLDIProofs_instDecidableWF(v_w__lo_652_, v_w__hi_653_, v_r_654_);
lean_dec(v_w__hi_653_);
lean_dec(v_w__lo_652_);
v_r_656_ = lean_box(v_res_655_);
return v_r_656_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableIF__state(lean_object* v_w__lo_657_, lean_object* v_w__hi_658_, lean_object* v_r_659_){
_start:
{
uint8_t v___x_660_; 
v___x_660_ = lp_parametric_PLDIProofs_instDecidableWF(v_w__lo_657_, v_w__hi_658_, v_r_659_);
if (v___x_660_ == 0)
{
uint8_t v___x_661_; 
v___x_661_ = 1;
return v___x_661_;
}
else
{
uint8_t v___x_662_; 
v___x_662_ = 0;
return v___x_662_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableIF__state___boxed(lean_object* v_w__lo_663_, lean_object* v_w__hi_664_, lean_object* v_r_665_){
_start:
{
uint8_t v_res_666_; lean_object* v_r_667_; 
v_res_666_ = lp_parametric_PLDIProofs_instDecidableIF__state(v_w__lo_663_, v_w__hi_664_, v_r_665_);
lean_dec(v_w__hi_664_);
lean_dec(v_w__lo_663_);
v_r_667_ = lean_box(v_res_666_);
return v_r_667_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__0(void){
_start:
{
lean_object* v___x_668_; lean_object* v___x_669_; lean_object* v___x_670_; 
v___x_668_ = lean_unsigned_to_nat(0u);
v___x_669_ = lean_unsigned_to_nat(64u);
v___x_670_ = l_BitVec_ofNat(v___x_669_, v___x_668_);
return v___x_670_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__1(void){
_start:
{
lean_object* v___x_671_; lean_object* v___x_672_; lean_object* v___x_673_; 
v___x_671_ = lean_unsigned_to_nat(15u);
v___x_672_ = lean_unsigned_to_nat(64u);
v___x_673_ = l_BitVec_ofNat(v___x_672_, v___x_671_);
return v___x_673_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__2(void){
_start:
{
lean_object* v___x_674_; lean_object* v___x_675_; lean_object* v___x_676_; 
v___x_674_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__1, &lp_parametric_PLDIProofs_motivating__R0___closed__1_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__1);
v___x_675_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__0, &lp_parametric_PLDIProofs_motivating__R0___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__0);
v___x_676_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_676_, 0, v___x_675_);
lean_ctor_set(v___x_676_, 1, v___x_674_);
return v___x_676_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__3(void){
_start:
{
lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; 
v___x_677_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__1, &lp_parametric_PLDIProofs_motivating__R0___closed__1_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__1);
v___x_678_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__0, &lp_parametric_PLDIProofs_motivating__R0___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__0);
v___x_679_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_679_, 0, v___x_678_);
lean_ctor_set(v___x_679_, 1, v___x_677_);
return v___x_679_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__4(void){
_start:
{
lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; 
v___x_680_ = lean_unsigned_to_nat(0u);
v___x_681_ = lean_unsigned_to_nat(32u);
v___x_682_ = l_BitVec_ofNat(v___x_681_, v___x_680_);
return v___x_682_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__5(void){
_start:
{
lean_object* v___x_683_; lean_object* v___x_684_; lean_object* v___x_685_; 
v___x_683_ = lean_unsigned_to_nat(15u);
v___x_684_ = lean_unsigned_to_nat(32u);
v___x_685_ = l_BitVec_ofNat(v___x_684_, v___x_683_);
return v___x_685_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__6(void){
_start:
{
lean_object* v___x_686_; lean_object* v___x_687_; lean_object* v___x_688_; 
v___x_686_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__5, &lp_parametric_PLDIProofs_motivating__R0___closed__5_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__5);
v___x_687_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__4, &lp_parametric_PLDIProofs_motivating__R0___closed__4_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__4);
v___x_688_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_688_, 0, v___x_687_);
lean_ctor_set(v___x_688_, 1, v___x_686_);
return v___x_688_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__7(void){
_start:
{
lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; 
v___x_689_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__5, &lp_parametric_PLDIProofs_motivating__R0___closed__5_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__5);
v___x_690_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__4, &lp_parametric_PLDIProofs_motivating__R0___closed__4_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__4);
v___x_691_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_691_, 0, v___x_690_);
lean_ctor_set(v___x_691_, 1, v___x_689_);
return v___x_691_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__8(void){
_start:
{
lean_object* v___x_692_; lean_object* v___x_693_; lean_object* v___x_694_; 
v___x_692_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__0, &lp_parametric_PLDIProofs_motivating__R0___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__0);
v___x_693_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__1, &lp_parametric_PLDIProofs_motivating__R0___closed__1_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__1);
v___x_694_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_694_, 0, v___x_693_);
lean_ctor_set(v___x_694_, 1, v___x_692_);
return v___x_694_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0___closed__9(void){
_start:
{
lean_object* v___x_695_; lean_object* v___x_696_; lean_object* v___x_697_; lean_object* v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; 
v___x_695_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__8, &lp_parametric_PLDIProofs_motivating__R0___closed__8_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__8);
v___x_696_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__7, &lp_parametric_PLDIProofs_motivating__R0___closed__7_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__7);
v___x_697_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__6, &lp_parametric_PLDIProofs_motivating__R0___closed__6_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__6);
v___x_698_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__3, &lp_parametric_PLDIProofs_motivating__R0___closed__3_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__3);
v___x_699_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__2, &lp_parametric_PLDIProofs_motivating__R0___closed__2_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__2);
v___x_700_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_700_, 0, v___x_699_);
lean_ctor_set(v___x_700_, 1, v___x_698_);
lean_ctor_set(v___x_700_, 2, v___x_697_);
lean_ctor_set(v___x_700_, 3, v___x_696_);
lean_ctor_set(v___x_700_, 4, v___x_695_);
return v___x_700_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R0(void){
_start:
{
lean_object* v___x_701_; 
v___x_701_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__9, &lp_parametric_PLDIProofs_motivating__R0___closed__9_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__9);
return v___x_701_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R1__EI___closed__0(void){
_start:
{
lean_object* v___x_702_; lean_object* v___x_703_; lean_object* v___x_704_; 
v___x_702_ = lean_unsigned_to_nat(10u);
v___x_703_ = lean_unsigned_to_nat(64u);
v___x_704_ = l_BitVec_ofNat(v___x_703_, v___x_702_);
return v___x_704_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R1__EI___closed__1(void){
_start:
{
lean_object* v___x_705_; lean_object* v___x_706_; lean_object* v___x_707_; 
v___x_705_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R1__EI___closed__0, &lp_parametric_PLDIProofs_motivating__R1__EI___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R1__EI___closed__0);
v___x_706_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__0, &lp_parametric_PLDIProofs_motivating__R0___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__0);
v___x_707_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_707_, 0, v___x_706_);
lean_ctor_set(v___x_707_, 1, v___x_705_);
return v___x_707_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R1__EI(void){
_start:
{
lean_object* v___x_708_; lean_object* v_s64_709_; lean_object* v_u32_710_; lean_object* v_s32_711_; lean_object* v_tnum_712_; lean_object* v___x_713_; lean_object* v___x_714_; 
v___x_708_ = lp_parametric_PLDIProofs_motivating__R0;
v_s64_709_ = lean_ctor_get(v___x_708_, 1);
v_u32_710_ = lean_ctor_get(v___x_708_, 2);
v_s32_711_ = lean_ctor_get(v___x_708_, 3);
v_tnum_712_ = lean_ctor_get(v___x_708_, 4);
v___x_713_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R1__EI___closed__1, &lp_parametric_PLDIProofs_motivating__R1__EI___closed__1_once, _init_lp_parametric_PLDIProofs_motivating__R1__EI___closed__1);
lean_inc_ref(v_tnum_712_);
lean_inc_ref(v_s32_711_);
lean_inc_ref(v_u32_710_);
lean_inc_ref(v_s64_709_);
v___x_714_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_714_, 0, v___x_713_);
lean_ctor_set(v___x_714_, 1, v_s64_709_);
lean_ctor_set(v___x_714_, 2, v_u32_710_);
lean_ctor_set(v___x_714_, 3, v_s32_711_);
lean_ctor_set(v___x_714_, 4, v_tnum_712_);
return v___x_714_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R2__IF___closed__0(void){
_start:
{
lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; 
v___x_715_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R1__EI___closed__0, &lp_parametric_PLDIProofs_motivating__R1__EI___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R1__EI___closed__0);
v___x_716_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__1, &lp_parametric_PLDIProofs_motivating__R0___closed__1_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__1);
v___x_717_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_717_, 0, v___x_716_);
lean_ctor_set(v___x_717_, 1, v___x_715_);
return v___x_717_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_motivating__R2__IF(void){
_start:
{
lean_object* v___x_718_; lean_object* v_s64_719_; lean_object* v_u32_720_; lean_object* v_s32_721_; lean_object* v_tnum_722_; lean_object* v___x_723_; lean_object* v___x_724_; 
v___x_718_ = lp_parametric_PLDIProofs_motivating__R1__EI;
v_s64_719_ = lean_ctor_get(v___x_718_, 1);
v_u32_720_ = lean_ctor_get(v___x_718_, 2);
v_s32_721_ = lean_ctor_get(v___x_718_, 3);
v_tnum_722_ = lean_ctor_get(v___x_718_, 4);
v___x_723_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R2__IF___closed__0, &lp_parametric_PLDIProofs_motivating__R2__IF___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R2__IF___closed__0);
lean_inc_ref(v_tnum_722_);
lean_inc_ref(v_s32_721_);
lean_inc_ref(v_u32_720_);
lean_inc_ref(v_s64_719_);
v___x_724_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_724_, 0, v___x_723_);
lean_ctor_set(v___x_724_, 1, v_s64_719_);
lean_ctor_set(v___x_724_, 2, v_u32_720_);
lean_ctor_set(v___x_724_, 3, v_s32_721_);
lean_ctor_set(v___x_724_, 4, v_tnum_722_);
return v___x_724_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_tnum__step___closed__0(void){
_start:
{
lean_object* v_zero_725_; lean_object* v___x_726_; 
v_zero_725_ = lean_unsigned_to_nat(0u);
v___x_726_ = l_BitVec_ofNat(v_zero_725_, v_zero_725_);
return v___x_726_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnum__step(lean_object* v_w_727_, lean_object* v_t_728_, lean_object* v_z_729_){
_start:
{
lean_object* v_zero_730_; uint8_t v_isZero_731_; 
v_zero_730_ = lean_unsigned_to_nat(0u);
v_isZero_731_ = lean_nat_dec_eq(v_w_727_, v_zero_730_);
if (v_isZero_731_ == 1)
{
lean_object* v___x_732_; 
v___x_732_ = lean_obj_once(&lp_parametric_PLDIProofs_tnum__step___closed__0, &lp_parametric_PLDIProofs_tnum__step___closed__0_once, _init_lp_parametric_PLDIProofs_tnum__step___closed__0);
return v___x_732_;
}
else
{
lean_object* v_one_733_; lean_object* v_n_734_; lean_object* v___x_735_; uint8_t v___y_737_; lean_object* v___y_738_; lean_object* v___y_739_; lean_object* v___y_740_; uint8_t v___y_741_; uint8_t v___y_755_; uint8_t v___x_762_; 
v_one_733_ = lean_unsigned_to_nat(1u);
v_n_734_ = lean_nat_sub(v_w_727_, v_one_733_);
v___x_735_ = lean_nat_add(v_n_734_, v_one_733_);
v___x_762_ = lean_nat_dec_lt(v_zero_730_, v___x_735_);
if (v___x_762_ == 0)
{
v___y_755_ = v___x_762_;
goto v___jp_754_;
}
else
{
lean_object* v___x_763_; uint8_t v___x_764_; 
v___x_763_ = lean_nat_sub(v___x_735_, v_one_733_);
v___x_764_ = l_Nat_testBit(v_z_729_, v___x_763_);
lean_dec(v___x_763_);
v___y_755_ = v___x_764_;
goto v___jp_754_;
}
v___jp_736_:
{
lean_object* v_v__lo_742_; lean_object* v_m__lo_743_; lean_object* v_t__lo_744_; uint8_t v___x_745_; 
v_v__lo_742_ = l_BitVec_setWidth(v___x_735_, v_n_734_, v___y_738_);
v_m__lo_743_ = l_BitVec_setWidth(v___x_735_, v_n_734_, v___y_740_);
lean_dec(v___x_735_);
lean_inc(v_m__lo_743_);
lean_inc(v_v__lo_742_);
v_t__lo_744_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_t__lo_744_, 0, v_v__lo_742_);
lean_ctor_set(v_t__lo_744_, 1, v_m__lo_743_);
v___x_745_ = 1;
if (v___y_737_ == 0)
{
if (v___y_741_ == 0)
{
lean_object* v___x_746_; uint8_t v___x_747_; 
v___x_746_ = lean_nat_lor(v_v__lo_742_, v_m__lo_743_);
lean_dec(v_m__lo_743_);
v___x_747_ = lean_nat_dec_lt(v___y_739_, v___x_746_);
lean_dec(v___x_746_);
if (v___x_747_ == 0)
{
lean_object* v___x_748_; 
lean_dec_ref_known(v_t__lo_744_, 2);
lean_dec(v___y_739_);
v___x_748_ = l_BitVec_cons(v_n_734_, v___x_745_, v_v__lo_742_);
lean_dec(v_v__lo_742_);
lean_dec(v_n_734_);
return v___x_748_;
}
else
{
lean_object* v___x_749_; lean_object* v___x_750_; 
lean_dec(v_v__lo_742_);
v___x_749_ = lp_parametric_PLDIProofs_tnum__step(v_n_734_, v_t__lo_744_, v___y_739_);
lean_dec(v___y_739_);
lean_dec_ref_known(v_t__lo_744_, 2);
v___x_750_ = l_BitVec_cons(v_n_734_, v___y_741_, v___x_749_);
lean_dec(v___x_749_);
lean_dec(v_n_734_);
return v___x_750_;
}
}
else
{
lean_object* v___x_751_; 
lean_dec_ref_known(v_t__lo_744_, 2);
lean_dec(v_m__lo_743_);
lean_dec(v___y_739_);
v___x_751_ = l_BitVec_cons(v_n_734_, v___x_745_, v_v__lo_742_);
lean_dec(v_v__lo_742_);
lean_dec(v_n_734_);
return v___x_751_;
}
}
else
{
lean_object* v___x_752_; lean_object* v___x_753_; 
lean_dec(v_m__lo_743_);
lean_dec(v_v__lo_742_);
v___x_752_ = lp_parametric_PLDIProofs_tnum__step(v_n_734_, v_t__lo_744_, v___y_739_);
lean_dec(v___y_739_);
lean_dec_ref_known(v_t__lo_744_, 2);
v___x_753_ = l_BitVec_cons(v_n_734_, v___x_745_, v___x_752_);
lean_dec(v___x_752_);
lean_dec(v_n_734_);
return v___x_753_;
}
}
v___jp_754_:
{
lean_object* v_v_756_; lean_object* v_m_757_; lean_object* v_z__lo_758_; uint8_t v___x_759_; 
v_v_756_ = lean_ctor_get(v_t_728_, 0);
v_m_757_ = lean_ctor_get(v_t_728_, 1);
v_z__lo_758_ = l_BitVec_setWidth(v___x_735_, v_n_734_, v_z_729_);
v___x_759_ = lean_nat_dec_lt(v_zero_730_, v___x_735_);
if (v___x_759_ == 0)
{
v___y_737_ = v___y_755_;
v___y_738_ = v_v_756_;
v___y_739_ = v_z__lo_758_;
v___y_740_ = v_m_757_;
v___y_741_ = v___x_759_;
goto v___jp_736_;
}
else
{
lean_object* v___x_760_; uint8_t v___x_761_; 
v___x_760_ = lean_nat_sub(v___x_735_, v_one_733_);
v___x_761_ = l_Nat_testBit(v_v_756_, v___x_760_);
lean_dec(v___x_760_);
v___y_737_ = v___y_755_;
v___y_738_ = v_v_756_;
v___y_739_ = v_z__lo_758_;
v___y_740_ = v_m_757_;
v___y_741_ = v___x_761_;
goto v___jp_736_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnum__step___boxed(lean_object* v_w_765_, lean_object* v_t_766_, lean_object* v_z_767_){
_start:
{
lean_object* v_res_768_; 
v_res_768_ = lp_parametric_PLDIProofs_tnum__step(v_w_765_, v_t_766_, v_z_767_);
lean_dec(v_z_767_);
lean_dec_ref(v_t_766_);
lean_dec(v_w_765_);
return v_res_768_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0(lean_object* v_w_769_, lean_object* v_m_770_, lean_object* v_v_771_, lean_object* v_x_772_){
_start:
{
lean_object* v___x_773_; lean_object* v___x_774_; uint8_t v___x_775_; 
v___x_773_ = l_BitVec_not(v_w_769_, v_m_770_);
v___x_774_ = lean_nat_land(v_x_772_, v___x_773_);
lean_dec(v___x_773_);
v___x_775_ = lean_nat_dec_eq(v___x_774_, v_v_771_);
lean_dec(v___x_774_);
return v___x_775_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0___boxed(lean_object* v_w_776_, lean_object* v_m_777_, lean_object* v_v_778_, lean_object* v_x_779_){
_start:
{
uint8_t v_res_780_; lean_object* v_r_781_; 
v_res_780_ = lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0(v_w_776_, v_m_777_, v_v_778_, v_x_779_);
lean_dec(v_x_779_);
lean_dec(v_v_778_);
lean_dec(v_m_777_);
lean_dec(v_w_776_);
v_r_781_ = lean_box(v_res_780_);
return v_r_781_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumSteppableDomain(lean_object* v_w_782_, lean_object* v_t_783_){
_start:
{
lean_object* v_v_784_; lean_object* v_m_785_; lean_object* v___f_786_; lean_object* v___x_787_; lean_object* v___x_788_; lean_object* v___x_789_; 
v_v_784_ = lean_ctor_get(v_t_783_, 0);
lean_inc_n(v_v_784_, 2);
v_m_785_ = lean_ctor_get(v_t_783_, 1);
lean_inc(v_m_785_);
lean_inc(v_w_782_);
v___f_786_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_tnumSteppableDomain___lam__0___boxed), 4, 3);
lean_closure_set(v___f_786_, 0, v_w_782_);
lean_closure_set(v___f_786_, 1, v_m_785_);
lean_closure_set(v___f_786_, 2, v_v_784_);
v___x_787_ = lean_nat_lor(v_v_784_, v_m_785_);
v___x_788_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_tnum__step___boxed), 3, 2);
lean_closure_set(v___x_788_, 0, v_w_782_);
lean_closure_set(v___x_788_, 1, v_t_783_);
v___x_789_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_789_, 0, v_v_784_);
lean_ctor_set(v___x_789_, 1, v___x_787_);
lean_ctor_set(v___x_789_, 2, v___f_786_);
lean_ctor_set(v___x_789_, 3, v___x_788_);
return v___x_789_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0(lean_object* v_min_790_, lean_object* v_max_791_, lean_object* v_x_792_){
_start:
{
uint8_t v___x_793_; 
v___x_793_ = lean_nat_dec_le(v_min_790_, v_x_792_);
if (v___x_793_ == 0)
{
return v___x_793_;
}
else
{
uint8_t v___x_794_; 
v___x_794_ = lean_nat_dec_le(v_x_792_, v_max_791_);
return v___x_794_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0___boxed(lean_object* v_min_795_, lean_object* v_max_796_, lean_object* v_x_797_){
_start:
{
uint8_t v_res_798_; lean_object* v_r_799_; 
v_res_798_ = lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0(v_min_795_, v_max_796_, v_x_797_);
lean_dec(v_x_797_);
lean_dec(v_max_796_);
lean_dec(v_min_795_);
v_r_799_ = lean_box(v_res_798_);
return v_r_799_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1(lean_object* v_min_800_, lean_object* v_w_801_, lean_object* v_z_802_){
_start:
{
uint8_t v___x_803_; 
v___x_803_ = lean_nat_dec_lt(v_z_802_, v_min_800_);
if (v___x_803_ == 0)
{
lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; 
v___x_804_ = lean_unsigned_to_nat(1u);
v___x_805_ = l_BitVec_ofNat(v_w_801_, v___x_804_);
v___x_806_ = l_BitVec_add(v_w_801_, v_z_802_, v___x_805_);
lean_dec(v___x_805_);
return v___x_806_;
}
else
{
lean_inc(v_min_800_);
return v_min_800_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1___boxed(lean_object* v_min_807_, lean_object* v_w_808_, lean_object* v_z_809_){
_start:
{
lean_object* v_res_810_; 
v_res_810_ = lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1(v_min_807_, v_w_808_, v_z_809_);
lean_dec(v_z_809_);
lean_dec(v_w_808_);
lean_dec(v_min_807_);
return v_res_810_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_uintervalSteppableDomain(lean_object* v_w_811_, lean_object* v_I_812_){
_start:
{
lean_object* v_min_813_; lean_object* v_max_814_; lean_object* v___f_815_; lean_object* v___f_816_; lean_object* v___x_817_; 
v_min_813_ = lean_ctor_get(v_I_812_, 0);
lean_inc_n(v_min_813_, 3);
v_max_814_ = lean_ctor_get(v_I_812_, 1);
lean_inc_n(v_max_814_, 2);
lean_dec_ref(v_I_812_);
v___f_815_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__0___boxed), 3, 2);
lean_closure_set(v___f_815_, 0, v_min_813_);
lean_closure_set(v___f_815_, 1, v_max_814_);
v___f_816_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_uintervalSteppableDomain___lam__1___boxed), 3, 2);
lean_closure_set(v___f_816_, 0, v_min_813_);
lean_closure_set(v___f_816_, 1, v_w_811_);
v___x_817_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_817_, 0, v_min_813_);
lean_ctor_set(v___x_817_, 1, v_max_814_);
lean_ctor_set(v___x_817_, 2, v___f_815_);
lean_ctor_set(v___x_817_, 3, v___f_816_);
return v___x_817_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_find_x3f___at___00PLDIProofs_multiDomainLoop_spec__0(lean_object* v_xc_818_, lean_object* v_x_819_){
_start:
{
if (lean_obj_tag(v_x_819_) == 0)
{
lean_object* v___x_820_; 
lean_dec(v_xc_818_);
v___x_820_ = lean_box(0);
return v___x_820_;
}
else
{
lean_object* v_head_821_; lean_object* v_tail_822_; lean_object* v_contains_823_; lean_object* v___x_824_; uint8_t v___x_825_; 
v_head_821_ = lean_ctor_get(v_x_819_, 0);
lean_inc(v_head_821_);
v_tail_822_ = lean_ctor_get(v_x_819_, 1);
lean_inc(v_tail_822_);
lean_dec_ref_known(v_x_819_, 2);
v_contains_823_ = lean_ctor_get(v_head_821_, 2);
lean_inc_ref(v_contains_823_);
lean_inc(v_xc_818_);
v___x_824_ = lean_apply_1(v_contains_823_, v_xc_818_);
v___x_825_ = lean_unbox(v___x_824_);
if (v___x_825_ == 0)
{
lean_object* v___x_826_; 
lean_dec(v_tail_822_);
lean_dec(v_xc_818_);
v___x_826_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_826_, 0, v_head_821_);
return v___x_826_;
}
else
{
lean_dec(v_head_821_);
v_x_819_ = v_tail_822_;
goto _start;
}
}
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multiDomainLoop___redArg(lean_object* v_ds_828_, lean_object* v_xmax_829_, lean_object* v_xc_830_, lean_object* v_x_831_){
_start:
{
lean_object* v_zero_832_; uint8_t v_isZero_833_; 
v_zero_832_ = lean_unsigned_to_nat(0u);
v_isZero_833_ = lean_nat_dec_eq(v_x_831_, v_zero_832_);
if (v_isZero_833_ == 1)
{
uint8_t v___x_834_; 
lean_dec(v_x_831_);
lean_dec(v_xc_830_);
lean_dec(v_ds_828_);
v___x_834_ = 0;
return v___x_834_;
}
else
{
uint8_t v___x_835_; 
v___x_835_ = lean_nat_dec_le(v_xc_830_, v_xmax_829_);
if (v___x_835_ == 0)
{
lean_dec(v_x_831_);
lean_dec(v_xc_830_);
lean_dec(v_ds_828_);
return v___x_835_;
}
else
{
lean_object* v___x_836_; 
lean_inc(v_ds_828_);
lean_inc(v_xc_830_);
v___x_836_ = lp_parametric_List_find_x3f___at___00PLDIProofs_multiDomainLoop_spec__0(v_xc_830_, v_ds_828_);
if (lean_obj_tag(v___x_836_) == 0)
{
lean_dec(v_x_831_);
lean_dec(v_xc_830_);
lean_dec(v_ds_828_);
return v___x_835_;
}
else
{
lean_object* v_val_837_; lean_object* v_max_838_; lean_object* v_step_839_; uint8_t v___x_840_; 
v_val_837_ = lean_ctor_get(v___x_836_, 0);
lean_inc(v_val_837_);
lean_dec_ref_known(v___x_836_, 1);
v_max_838_ = lean_ctor_get(v_val_837_, 1);
lean_inc(v_max_838_);
v_step_839_ = lean_ctor_get(v_val_837_, 3);
lean_inc_ref(v_step_839_);
lean_dec(v_val_837_);
v___x_840_ = lean_nat_dec_lt(v_xc_830_, v_max_838_);
lean_dec(v_max_838_);
if (v___x_840_ == 0)
{
lean_dec_ref(v_step_839_);
lean_dec(v_x_831_);
lean_dec(v_xc_830_);
lean_dec(v_ds_828_);
return v___x_840_;
}
else
{
lean_object* v_one_841_; lean_object* v_n_842_; lean_object* v___x_843_; 
v_one_841_ = lean_unsigned_to_nat(1u);
v_n_842_ = lean_nat_sub(v_x_831_, v_one_841_);
lean_dec(v_x_831_);
v___x_843_ = lean_apply_1(v_step_839_, v_xc_830_);
v_xc_830_ = v___x_843_;
v_x_831_ = v_n_842_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multiDomainLoop___redArg___boxed(lean_object* v_ds_845_, lean_object* v_xmax_846_, lean_object* v_xc_847_, lean_object* v_x_848_){
_start:
{
uint8_t v_res_849_; lean_object* v_r_850_; 
v_res_849_ = lp_parametric_PLDIProofs_multiDomainLoop___redArg(v_ds_845_, v_xmax_846_, v_xc_847_, v_x_848_);
lean_dec(v_xmax_846_);
v_r_850_ = lean_box(v_res_849_);
return v_r_850_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multiDomainLoop(lean_object* v_w_851_, lean_object* v_ds_852_, lean_object* v_xmax_853_, lean_object* v_xc_854_, lean_object* v_x_855_){
_start:
{
uint8_t v___x_856_; 
v___x_856_ = lp_parametric_PLDIProofs_multiDomainLoop___redArg(v_ds_852_, v_xmax_853_, v_xc_854_, v_x_855_);
return v___x_856_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multiDomainLoop___boxed(lean_object* v_w_857_, lean_object* v_ds_858_, lean_object* v_xmax_859_, lean_object* v_xc_860_, lean_object* v_x_861_){
_start:
{
uint8_t v_res_862_; lean_object* v_r_863_; 
v_res_862_ = lp_parametric_PLDIProofs_multiDomainLoop(v_w_857_, v_ds_858_, v_xmax_859_, v_xc_860_, v_x_861_);
lean_dec(v_xmax_859_);
lean_dec(v_w_857_);
v_r_863_ = lean_box(v_res_862_);
return v_r_863_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg(lean_object* v_as_864_, size_t v_i_865_, size_t v_stop_866_, lean_object* v_b_867_){
_start:
{
uint8_t v___x_868_; 
v___x_868_ = lean_usize_dec_eq(v_i_865_, v_stop_866_);
if (v___x_868_ == 0)
{
size_t v___x_869_; size_t v___x_870_; lean_object* v___x_871_; lean_object* v_min_872_; uint8_t v___x_873_; 
v___x_869_ = ((size_t)1ULL);
v___x_870_ = lean_usize_sub(v_i_865_, v___x_869_);
v___x_871_ = lean_array_uget_borrowed(v_as_864_, v___x_870_);
v_min_872_ = lean_ctor_get(v___x_871_, 0);
v___x_873_ = lean_nat_dec_le(v_b_867_, v_min_872_);
if (v___x_873_ == 0)
{
v_i_865_ = v___x_870_;
goto _start;
}
else
{
v_i_865_ = v___x_870_;
v_b_867_ = v_min_872_;
goto _start;
}
}
else
{
lean_inc(v_b_867_);
return v_b_867_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg___boxed(lean_object* v_as_876_, lean_object* v_i_877_, lean_object* v_stop_878_, lean_object* v_b_879_){
_start:
{
size_t v_i_boxed_880_; size_t v_stop_boxed_881_; lean_object* v_res_882_; 
v_i_boxed_880_ = lean_unbox_usize(v_i_877_);
lean_dec(v_i_877_);
v_stop_boxed_881_ = lean_unbox_usize(v_stop_878_);
lean_dec(v_stop_878_);
v_res_882_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg(v_as_876_, v_i_boxed_880_, v_stop_boxed_881_, v_b_879_);
lean_dec(v_b_879_);
lean_dec_ref(v_as_876_);
return v_res_882_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0(lean_object* v_w_883_, lean_object* v_init_884_, lean_object* v_l_885_){
_start:
{
lean_object* v___x_886_; lean_object* v___x_887_; lean_object* v___x_888_; uint8_t v___x_889_; 
v___x_886_ = lean_array_mk(v_l_885_);
v___x_887_ = lean_array_get_size(v___x_886_);
v___x_888_ = lean_unsigned_to_nat(0u);
v___x_889_ = lean_nat_dec_lt(v___x_888_, v___x_887_);
if (v___x_889_ == 0)
{
lean_dec_ref(v___x_886_);
lean_inc(v_init_884_);
return v_init_884_;
}
else
{
size_t v___x_890_; size_t v___x_891_; lean_object* v___x_892_; 
v___x_890_ = lean_usize_of_nat(v___x_887_);
v___x_891_ = ((size_t)0ULL);
v___x_892_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg(v___x_886_, v___x_890_, v___x_891_, v_init_884_);
lean_dec_ref(v___x_886_);
return v___x_892_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0___boxed(lean_object* v_w_893_, lean_object* v_init_894_, lean_object* v_l_895_){
_start:
{
lean_object* v_res_896_; 
v_res_896_ = lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0(v_w_893_, v_init_894_, v_l_895_);
lean_dec(v_init_894_);
lean_dec(v_w_893_);
return v_res_896_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMin(lean_object* v_w_897_, lean_object* v_ds_898_){
_start:
{
lean_object* v___x_899_; lean_object* v___x_900_; lean_object* v___x_901_; 
v___x_899_ = lean_unsigned_to_nat(0u);
v___x_900_ = l_BitVec_ofNat(v_w_897_, v___x_899_);
v___x_901_ = lp_parametric_List_foldrTR___at___00PLDIProofs_domainMin_spec__0(v_w_897_, v___x_900_, v_ds_898_);
lean_dec(v___x_900_);
return v___x_901_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMin___boxed(lean_object* v_w_902_, lean_object* v_ds_903_){
_start:
{
lean_object* v_res_904_; 
v_res_904_ = lp_parametric_PLDIProofs_domainMin(v_w_902_, v_ds_903_);
lean_dec(v_w_902_);
return v_res_904_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0(lean_object* v_w_905_, lean_object* v_as_906_, size_t v_i_907_, size_t v_stop_908_, lean_object* v_b_909_){
_start:
{
lean_object* v___x_910_; 
v___x_910_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___redArg(v_as_906_, v_i_907_, v_stop_908_, v_b_909_);
return v___x_910_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0___boxed(lean_object* v_w_911_, lean_object* v_as_912_, lean_object* v_i_913_, lean_object* v_stop_914_, lean_object* v_b_915_){
_start:
{
size_t v_i_boxed_916_; size_t v_stop_boxed_917_; lean_object* v_res_918_; 
v_i_boxed_916_ = lean_unbox_usize(v_i_913_);
lean_dec(v_i_913_);
v_stop_boxed_917_ = lean_unbox_usize(v_stop_914_);
lean_dec(v_stop_914_);
v_res_918_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMin_spec__0_spec__0(v_w_911_, v_as_912_, v_i_boxed_916_, v_stop_boxed_917_, v_b_915_);
lean_dec(v_b_915_);
lean_dec_ref(v_as_912_);
lean_dec(v_w_911_);
return v_res_918_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg(lean_object* v_as_919_, size_t v_i_920_, size_t v_stop_921_, lean_object* v_b_922_){
_start:
{
uint8_t v___x_923_; 
v___x_923_ = lean_usize_dec_eq(v_i_920_, v_stop_921_);
if (v___x_923_ == 0)
{
size_t v___x_924_; size_t v___x_925_; lean_object* v___x_926_; lean_object* v_max_927_; uint8_t v___x_928_; 
v___x_924_ = ((size_t)1ULL);
v___x_925_ = lean_usize_sub(v_i_920_, v___x_924_);
v___x_926_ = lean_array_uget_borrowed(v_as_919_, v___x_925_);
v_max_927_ = lean_ctor_get(v___x_926_, 1);
v___x_928_ = lean_nat_dec_le(v_max_927_, v_b_922_);
if (v___x_928_ == 0)
{
v_i_920_ = v___x_925_;
goto _start;
}
else
{
v_i_920_ = v___x_925_;
v_b_922_ = v_max_927_;
goto _start;
}
}
else
{
lean_inc(v_b_922_);
return v_b_922_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg___boxed(lean_object* v_as_931_, lean_object* v_i_932_, lean_object* v_stop_933_, lean_object* v_b_934_){
_start:
{
size_t v_i_boxed_935_; size_t v_stop_boxed_936_; lean_object* v_res_937_; 
v_i_boxed_935_ = lean_unbox_usize(v_i_932_);
lean_dec(v_i_932_);
v_stop_boxed_936_ = lean_unbox_usize(v_stop_933_);
lean_dec(v_stop_933_);
v_res_937_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg(v_as_931_, v_i_boxed_935_, v_stop_boxed_936_, v_b_934_);
lean_dec(v_b_934_);
lean_dec_ref(v_as_931_);
return v_res_937_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0(lean_object* v_w_938_, lean_object* v_init_939_, lean_object* v_l_940_){
_start:
{
lean_object* v___x_941_; lean_object* v___x_942_; lean_object* v___x_943_; uint8_t v___x_944_; 
v___x_941_ = lean_array_mk(v_l_940_);
v___x_942_ = lean_array_get_size(v___x_941_);
v___x_943_ = lean_unsigned_to_nat(0u);
v___x_944_ = lean_nat_dec_lt(v___x_943_, v___x_942_);
if (v___x_944_ == 0)
{
lean_dec_ref(v___x_941_);
lean_inc(v_init_939_);
return v_init_939_;
}
else
{
size_t v___x_945_; size_t v___x_946_; lean_object* v___x_947_; 
v___x_945_ = lean_usize_of_nat(v___x_942_);
v___x_946_ = ((size_t)0ULL);
v___x_947_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg(v___x_941_, v___x_945_, v___x_946_, v_init_939_);
lean_dec_ref(v___x_941_);
return v___x_947_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0___boxed(lean_object* v_w_948_, lean_object* v_init_949_, lean_object* v_l_950_){
_start:
{
lean_object* v_res_951_; 
v_res_951_ = lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0(v_w_948_, v_init_949_, v_l_950_);
lean_dec(v_init_949_);
lean_dec(v_w_948_);
return v_res_951_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMax(lean_object* v_w_952_, lean_object* v_ds_953_){
_start:
{
lean_object* v___x_954_; lean_object* v___x_955_; 
v___x_954_ = l_BitVec_allOnes(v_w_952_);
v___x_955_ = lp_parametric_List_foldrTR___at___00PLDIProofs_domainMax_spec__0(v_w_952_, v___x_954_, v_ds_953_);
lean_dec(v___x_954_);
return v___x_955_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_domainMax___boxed(lean_object* v_w_956_, lean_object* v_ds_957_){
_start:
{
lean_object* v_res_958_; 
v_res_958_ = lp_parametric_PLDIProofs_domainMax(v_w_956_, v_ds_957_);
lean_dec(v_w_956_);
return v_res_958_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0(lean_object* v_w_959_, lean_object* v_as_960_, size_t v_i_961_, size_t v_stop_962_, lean_object* v_b_963_){
_start:
{
lean_object* v___x_964_; 
v___x_964_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___redArg(v_as_960_, v_i_961_, v_stop_962_, v_b_963_);
return v___x_964_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0___boxed(lean_object* v_w_965_, lean_object* v_as_966_, lean_object* v_i_967_, lean_object* v_stop_968_, lean_object* v_b_969_){
_start:
{
size_t v_i_boxed_970_; size_t v_stop_boxed_971_; lean_object* v_res_972_; 
v_i_boxed_970_ = lean_unbox_usize(v_i_967_);
lean_dec(v_i_967_);
v_stop_boxed_971_ = lean_unbox_usize(v_stop_968_);
lean_dec(v_stop_968_);
v_res_972_ = lp_parametric___private_Init_Data_Array_Basic_0__Array_foldrMUnsafe_fold___at___00List_foldrTR___at___00PLDIProofs_domainMax_spec__0_spec__0(v_w_965_, v_as_966_, v_i_boxed_970_, v_stop_boxed_971_, v_b_969_);
lean_dec(v_b_969_);
lean_dec_ref(v_as_966_);
lean_dec(v_w_965_);
return v_res_972_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_multi__domain__intersect(lean_object* v_w_973_, lean_object* v_ds_974_){
_start:
{
lean_object* v_xmin_975_; lean_object* v_xmax_976_; lean_object* v___x_977_; lean_object* v___x_978_; lean_object* v___x_979_; uint8_t v___x_980_; 
lean_inc_n(v_ds_974_, 2);
v_xmin_975_ = lp_parametric_PLDIProofs_domainMin(v_w_973_, v_ds_974_);
v_xmax_976_ = lp_parametric_PLDIProofs_domainMax(v_w_973_, v_ds_974_);
v___x_977_ = lean_unsigned_to_nat(1u);
v___x_978_ = lean_nat_add(v_xmax_976_, v___x_977_);
v___x_979_ = lean_nat_sub(v___x_978_, v_xmin_975_);
lean_dec(v___x_978_);
v___x_980_ = lp_parametric_PLDIProofs_multiDomainLoop___redArg(v_ds_974_, v_xmax_976_, v_xmin_975_, v___x_979_);
lean_dec(v_xmax_976_);
return v___x_980_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_multi__domain__intersect___boxed(lean_object* v_w_981_, lean_object* v_ds_982_){
_start:
{
uint8_t v_res_983_; lean_object* v_r_984_; 
v_res_983_ = lp_parametric_PLDIProofs_multi__domain__intersect(v_w_981_, v_ds_982_);
lean_dec(v_w_981_);
v_r_984_ = lean_box(v_res_983_);
return v_r_984_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter___redArg(lean_object* v_x_985_, lean_object* v_h__1_986_, lean_object* v_h__2_987_){
_start:
{
if (lean_obj_tag(v_x_985_) == 0)
{
lean_object* v___x_988_; lean_object* v___x_989_; 
lean_dec(v_h__2_987_);
v___x_988_ = lean_box(0);
v___x_989_ = lean_apply_1(v_h__1_986_, v___x_988_);
return v___x_989_;
}
else
{
lean_object* v_val_990_; lean_object* v___x_991_; 
lean_dec(v_h__1_986_);
v_val_990_ = lean_ctor_get(v_x_985_, 0);
lean_inc(v_val_990_);
lean_dec_ref_known(v_x_985_, 1);
v___x_991_ = lean_apply_1(v_h__2_987_, v_val_990_);
return v___x_991_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter(lean_object* v_w_992_, lean_object* v_motive_993_, lean_object* v_x_994_, lean_object* v_h__1_995_, lean_object* v_h__2_996_){
_start:
{
if (lean_obj_tag(v_x_994_) == 0)
{
lean_object* v___x_997_; lean_object* v___x_998_; 
lean_dec(v_h__2_996_);
v___x_997_ = lean_box(0);
v___x_998_ = lean_apply_1(v_h__1_995_, v___x_997_);
return v___x_998_;
}
else
{
lean_object* v_val_999_; lean_object* v___x_1000_; 
lean_dec(v_h__1_995_);
v_val_999_ = lean_ctor_get(v_x_994_, 0);
lean_inc(v_val_999_);
lean_dec_ref_known(v_x_994_, 1);
v___x_1000_ = lean_apply_1(v_h__2_996_, v_val_999_);
return v___x_1000_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter___boxed(lean_object* v_w_1001_, lean_object* v_motive_1002_, lean_object* v_x_1003_, lean_object* v_h__1_1004_, lean_object* v_h__2_1005_){
_start:
{
lean_object* v_res_1006_; 
v_res_1006_ = lp_parametric___private_PLDIProofs_0__PLDIProofs_multiDomainLoop_match__1_splitter(v_w_1001_, v_motive_1002_, v_x_1003_, v_h__1_1004_, v_h__2_1005_);
lean_dec(v_w_1001_);
return v_res_1006_;
}
}
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg(lean_object* v_d1_1007_, lean_object* v_x_1008_){
_start:
{
if (lean_obj_tag(v_x_1008_) == 0)
{
uint8_t v___x_1009_; 
lean_dec_ref(v_d1_1007_);
v___x_1009_ = 0;
return v___x_1009_;
}
else
{
lean_object* v_head_1010_; lean_object* v_tail_1011_; uint8_t v___y_1013_; lean_object* v_max_1015_; lean_object* v_contains_1016_; lean_object* v_step_1017_; lean_object* v_min_1018_; lean_object* v_max_1019_; lean_object* v___x_1020_; uint8_t v___x_1021_; 
v_head_1010_ = lean_ctor_get(v_x_1008_, 0);
lean_inc(v_head_1010_);
v_tail_1011_ = lean_ctor_get(v_x_1008_, 1);
lean_inc(v_tail_1011_);
lean_dec_ref_known(v_x_1008_, 2);
v_max_1015_ = lean_ctor_get(v_d1_1007_, 1);
v_contains_1016_ = lean_ctor_get(v_d1_1007_, 2);
v_step_1017_ = lean_ctor_get(v_d1_1007_, 3);
v_min_1018_ = lean_ctor_get(v_head_1010_, 0);
lean_inc_n(v_min_1018_, 2);
v_max_1019_ = lean_ctor_get(v_head_1010_, 1);
lean_inc(v_max_1019_);
lean_dec(v_head_1010_);
lean_inc_ref(v_contains_1016_);
v___x_1020_ = lean_apply_1(v_contains_1016_, v_min_1018_);
v___x_1021_ = lean_unbox(v___x_1020_);
if (v___x_1021_ == 0)
{
uint8_t v___x_1022_; 
v___x_1022_ = lean_nat_dec_lt(v_min_1018_, v_max_1015_);
if (v___x_1022_ == 0)
{
lean_dec(v_max_1019_);
lean_dec(v_min_1018_);
v___y_1013_ = v___x_1022_;
goto v___jp_1012_;
}
else
{
lean_object* v___x_1023_; uint8_t v___x_1024_; 
lean_inc_ref(v_step_1017_);
v___x_1023_ = lean_apply_1(v_step_1017_, v_min_1018_);
v___x_1024_ = lean_nat_dec_le(v___x_1023_, v_max_1019_);
lean_dec(v_max_1019_);
lean_dec(v___x_1023_);
v___y_1013_ = v___x_1024_;
goto v___jp_1012_;
}
}
else
{
uint8_t v___x_1025_; 
lean_dec(v_max_1019_);
lean_dec(v_min_1018_);
lean_dec(v_tail_1011_);
lean_dec_ref(v_d1_1007_);
v___x_1025_ = lean_unbox(v___x_1020_);
return v___x_1025_;
}
v___jp_1012_:
{
if (v___y_1013_ == 0)
{
v_x_1008_ = v_tail_1011_;
goto _start;
}
else
{
lean_dec(v_tail_1011_);
lean_dec_ref(v_d1_1007_);
return v___y_1013_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg___boxed(lean_object* v_d1_1026_, lean_object* v_x_1027_){
_start:
{
uint8_t v_res_1028_; lean_object* v_r_1029_; 
v_res_1028_ = lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg(v_d1_1026_, v_x_1027_);
v_r_1029_ = lean_box(v_res_1028_);
return v_r_1029_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_unrolledIntervalListIntersect(lean_object* v_w_1030_, lean_object* v_d1_1031_, lean_object* v_intervals_1032_){
_start:
{
uint8_t v___x_1033_; 
v___x_1033_ = lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg(v_d1_1031_, v_intervals_1032_);
return v___x_1033_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_unrolledIntervalListIntersect___boxed(lean_object* v_w_1034_, lean_object* v_d1_1035_, lean_object* v_intervals_1036_){
_start:
{
uint8_t v_res_1037_; lean_object* v_r_1038_; 
v_res_1037_ = lp_parametric_PLDIProofs_unrolledIntervalListIntersect(v_w_1034_, v_d1_1035_, v_intervals_1036_);
lean_dec(v_w_1034_);
v_r_1038_ = lean_box(v_res_1037_);
return v_r_1038_;
}
}
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0(lean_object* v_d1_1039_, lean_object* v_w_1040_, lean_object* v_x_1041_){
_start:
{
uint8_t v___x_1042_; 
v___x_1042_ = lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___redArg(v_d1_1039_, v_x_1041_);
return v___x_1042_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0___boxed(lean_object* v_d1_1043_, lean_object* v_w_1044_, lean_object* v_x_1045_){
_start:
{
uint8_t v_res_1046_; lean_object* v_r_1047_; 
v_res_1046_ = lp_parametric_List_any___at___00PLDIProofs_unrolledIntervalListIntersect_spec__0(v_d1_1043_, v_w_1044_, v_x_1045_);
lean_dec(v_w_1044_);
v_r_1047_ = lean_box(v_res_1046_);
return v_r_1047_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_fig3__D1___lam__0(lean_object* v___x_1048_, lean_object* v___x_1049_, lean_object* v___x_1050_, lean_object* v_x_1051_){
_start:
{
uint8_t v___y_1053_; uint8_t v___x_1064_; 
v___x_1064_ = lean_nat_dec_eq(v_x_1051_, v___x_1050_);
if (v___x_1064_ == 0)
{
lean_object* v___x_1065_; lean_object* v___x_1066_; uint8_t v___x_1067_; 
v___x_1065_ = lean_unsigned_to_nat(2u);
v___x_1066_ = l_BitVec_ofNat(v___x_1048_, v___x_1065_);
v___x_1067_ = lean_nat_dec_eq(v_x_1051_, v___x_1066_);
lean_dec(v___x_1066_);
v___y_1053_ = v___x_1067_;
goto v___jp_1052_;
}
else
{
v___y_1053_ = v___x_1064_;
goto v___jp_1052_;
}
v___jp_1052_:
{
if (v___y_1053_ == 0)
{
lean_object* v___x_1054_; lean_object* v___x_1055_; uint8_t v___x_1056_; 
v___x_1054_ = lean_unsigned_to_nat(5u);
v___x_1055_ = l_BitVec_ofNat(v___x_1048_, v___x_1054_);
v___x_1056_ = lean_nat_dec_eq(v_x_1051_, v___x_1055_);
lean_dec(v___x_1055_);
if (v___x_1056_ == 0)
{
lean_object* v___x_1057_; lean_object* v___x_1058_; uint8_t v___x_1059_; 
v___x_1057_ = lean_unsigned_to_nat(6u);
v___x_1058_ = l_BitVec_ofNat(v___x_1048_, v___x_1057_);
v___x_1059_ = lean_nat_dec_eq(v_x_1051_, v___x_1058_);
lean_dec(v___x_1058_);
if (v___x_1059_ == 0)
{
lean_object* v___x_1060_; lean_object* v___x_1061_; uint8_t v___x_1062_; 
v___x_1060_ = lean_unsigned_to_nat(9u);
v___x_1061_ = l_BitVec_ofNat(v___x_1048_, v___x_1060_);
v___x_1062_ = lean_nat_dec_eq(v_x_1051_, v___x_1061_);
lean_dec(v___x_1061_);
if (v___x_1062_ == 0)
{
uint8_t v___x_1063_; 
v___x_1063_ = lean_nat_dec_eq(v_x_1051_, v___x_1049_);
return v___x_1063_;
}
else
{
return v___x_1062_;
}
}
else
{
return v___x_1059_;
}
}
else
{
return v___x_1056_;
}
}
else
{
return v___y_1053_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__0___boxed(lean_object* v___x_1068_, lean_object* v___x_1069_, lean_object* v___x_1070_, lean_object* v_x_1071_){
_start:
{
uint8_t v_res_1072_; lean_object* v_r_1073_; 
v_res_1072_ = lp_parametric_PLDIProofs_fig3__D1___lam__0(v___x_1068_, v___x_1069_, v___x_1070_, v_x_1071_);
lean_dec(v_x_1071_);
lean_dec(v___x_1070_);
lean_dec(v___x_1069_);
lean_dec(v___x_1068_);
v_r_1073_ = lean_box(v_res_1072_);
return v_r_1073_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__1(lean_object* v___x_1074_, lean_object* v___x_1075_, lean_object* v___x_1076_, lean_object* v_z_1077_){
_start:
{
uint8_t v___x_1078_; 
v___x_1078_ = lean_nat_dec_lt(v_z_1077_, v___x_1074_);
if (v___x_1078_ == 0)
{
lean_object* v___x_1079_; lean_object* v___x_1080_; uint8_t v___x_1081_; 
v___x_1079_ = lean_unsigned_to_nat(2u);
v___x_1080_ = l_BitVec_ofNat(v___x_1075_, v___x_1079_);
v___x_1081_ = lean_nat_dec_lt(v_z_1077_, v___x_1080_);
if (v___x_1081_ == 0)
{
lean_object* v___x_1082_; lean_object* v___x_1083_; uint8_t v___x_1084_; 
lean_dec(v___x_1080_);
v___x_1082_ = lean_unsigned_to_nat(5u);
v___x_1083_ = l_BitVec_ofNat(v___x_1075_, v___x_1082_);
v___x_1084_ = lean_nat_dec_lt(v_z_1077_, v___x_1083_);
if (v___x_1084_ == 0)
{
lean_object* v___x_1085_; lean_object* v___x_1086_; uint8_t v___x_1087_; 
lean_dec(v___x_1083_);
v___x_1085_ = lean_unsigned_to_nat(6u);
v___x_1086_ = l_BitVec_ofNat(v___x_1075_, v___x_1085_);
v___x_1087_ = lean_nat_dec_lt(v_z_1077_, v___x_1086_);
if (v___x_1087_ == 0)
{
lean_object* v___x_1088_; lean_object* v___x_1089_; uint8_t v___x_1090_; 
lean_dec(v___x_1086_);
v___x_1088_ = lean_unsigned_to_nat(9u);
v___x_1089_ = l_BitVec_ofNat(v___x_1075_, v___x_1088_);
v___x_1090_ = lean_nat_dec_lt(v_z_1077_, v___x_1089_);
if (v___x_1090_ == 0)
{
lean_dec(v___x_1089_);
lean_inc(v___x_1076_);
return v___x_1076_;
}
else
{
return v___x_1089_;
}
}
else
{
return v___x_1086_;
}
}
else
{
return v___x_1083_;
}
}
else
{
return v___x_1080_;
}
}
else
{
lean_inc(v___x_1074_);
return v___x_1074_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D1___lam__1___boxed(lean_object* v___x_1091_, lean_object* v___x_1092_, lean_object* v___x_1093_, lean_object* v_z_1094_){
_start:
{
lean_object* v_res_1095_; 
v_res_1095_ = lp_parametric_PLDIProofs_fig3__D1___lam__1(v___x_1091_, v___x_1092_, v___x_1093_, v_z_1094_);
lean_dec(v_z_1094_);
lean_dec(v___x_1093_);
lean_dec(v___x_1092_);
lean_dec(v___x_1091_);
return v_res_1095_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1___closed__0(void){
_start:
{
lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; 
v___x_1096_ = lean_unsigned_to_nat(1u);
v___x_1097_ = lean_unsigned_to_nat(8u);
v___x_1098_ = l_BitVec_ofNat(v___x_1097_, v___x_1096_);
return v___x_1098_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1___closed__1(void){
_start:
{
lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; 
v___x_1099_ = lean_unsigned_to_nat(10u);
v___x_1100_ = lean_unsigned_to_nat(8u);
v___x_1101_ = l_BitVec_ofNat(v___x_1100_, v___x_1099_);
return v___x_1101_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1___closed__2(void){
_start:
{
lean_object* v___x_1102_; lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___f_1105_; 
v___x_1102_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__0, &lp_parametric_PLDIProofs_fig3__D1___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__0);
v___x_1103_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1104_ = lean_unsigned_to_nat(8u);
v___f_1105_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_fig3__D1___lam__0___boxed), 4, 3);
lean_closure_set(v___f_1105_, 0, v___x_1104_);
lean_closure_set(v___f_1105_, 1, v___x_1103_);
lean_closure_set(v___f_1105_, 2, v___x_1102_);
return v___f_1105_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1___closed__3(void){
_start:
{
lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___f_1109_; 
v___x_1106_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1107_ = lean_unsigned_to_nat(8u);
v___x_1108_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__0, &lp_parametric_PLDIProofs_fig3__D1___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__0);
v___f_1109_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_fig3__D1___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1109_, 0, v___x_1108_);
lean_closure_set(v___f_1109_, 1, v___x_1107_);
lean_closure_set(v___f_1109_, 2, v___x_1106_);
return v___f_1109_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1___closed__4(void){
_start:
{
lean_object* v___f_1110_; lean_object* v___f_1111_; lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1114_; 
v___f_1110_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__3, &lp_parametric_PLDIProofs_fig3__D1___closed__3_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__3);
v___f_1111_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__2, &lp_parametric_PLDIProofs_fig3__D1___closed__2_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__2);
v___x_1112_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1113_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__0, &lp_parametric_PLDIProofs_fig3__D1___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__0);
v___x_1114_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1114_, 0, v___x_1113_);
lean_ctor_set(v___x_1114_, 1, v___x_1112_);
lean_ctor_set(v___x_1114_, 2, v___f_1111_);
lean_ctor_set(v___x_1114_, 3, v___f_1110_);
return v___x_1114_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D1(void){
_start:
{
lean_object* v___x_1115_; 
v___x_1115_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__4, &lp_parametric_PLDIProofs_fig3__D1___closed__4_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__4);
return v___x_1115_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_fig3__D2___lam__0(lean_object* v___x_1116_, lean_object* v___x_1117_, lean_object* v___x_1118_, lean_object* v_x_1119_){
_start:
{
uint8_t v___y_1121_; uint8_t v___x_1132_; 
v___x_1132_ = lean_nat_dec_eq(v_x_1119_, v___x_1118_);
if (v___x_1132_ == 0)
{
lean_object* v___x_1133_; lean_object* v___x_1134_; uint8_t v___x_1135_; 
v___x_1133_ = lean_unsigned_to_nat(3u);
v___x_1134_ = l_BitVec_ofNat(v___x_1116_, v___x_1133_);
v___x_1135_ = lean_nat_dec_eq(v_x_1119_, v___x_1134_);
lean_dec(v___x_1134_);
v___y_1121_ = v___x_1135_;
goto v___jp_1120_;
}
else
{
v___y_1121_ = v___x_1132_;
goto v___jp_1120_;
}
v___jp_1120_:
{
if (v___y_1121_ == 0)
{
lean_object* v___x_1122_; lean_object* v___x_1123_; uint8_t v___x_1124_; 
v___x_1122_ = lean_unsigned_to_nat(4u);
v___x_1123_ = l_BitVec_ofNat(v___x_1116_, v___x_1122_);
v___x_1124_ = lean_nat_dec_eq(v_x_1119_, v___x_1123_);
lean_dec(v___x_1123_);
if (v___x_1124_ == 0)
{
lean_object* v___x_1125_; lean_object* v___x_1126_; uint8_t v___x_1127_; 
v___x_1125_ = lean_unsigned_to_nat(5u);
v___x_1126_ = l_BitVec_ofNat(v___x_1116_, v___x_1125_);
v___x_1127_ = lean_nat_dec_eq(v_x_1119_, v___x_1126_);
lean_dec(v___x_1126_);
if (v___x_1127_ == 0)
{
lean_object* v___x_1128_; lean_object* v___x_1129_; uint8_t v___x_1130_; 
v___x_1128_ = lean_unsigned_to_nat(9u);
v___x_1129_ = l_BitVec_ofNat(v___x_1116_, v___x_1128_);
v___x_1130_ = lean_nat_dec_eq(v_x_1119_, v___x_1129_);
lean_dec(v___x_1129_);
if (v___x_1130_ == 0)
{
uint8_t v___x_1131_; 
v___x_1131_ = lean_nat_dec_eq(v_x_1119_, v___x_1117_);
return v___x_1131_;
}
else
{
return v___x_1130_;
}
}
else
{
return v___x_1127_;
}
}
else
{
return v___x_1124_;
}
}
else
{
return v___y_1121_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__0___boxed(lean_object* v___x_1136_, lean_object* v___x_1137_, lean_object* v___x_1138_, lean_object* v_x_1139_){
_start:
{
uint8_t v_res_1140_; lean_object* v_r_1141_; 
v_res_1140_ = lp_parametric_PLDIProofs_fig3__D2___lam__0(v___x_1136_, v___x_1137_, v___x_1138_, v_x_1139_);
lean_dec(v_x_1139_);
lean_dec(v___x_1138_);
lean_dec(v___x_1137_);
lean_dec(v___x_1136_);
v_r_1141_ = lean_box(v_res_1140_);
return v_r_1141_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__1(lean_object* v___x_1142_, lean_object* v___x_1143_, lean_object* v___x_1144_, lean_object* v_z_1145_){
_start:
{
uint8_t v___x_1146_; 
v___x_1146_ = lean_nat_dec_lt(v_z_1145_, v___x_1142_);
if (v___x_1146_ == 0)
{
lean_object* v___x_1147_; lean_object* v___x_1148_; uint8_t v___x_1149_; 
v___x_1147_ = lean_unsigned_to_nat(3u);
v___x_1148_ = l_BitVec_ofNat(v___x_1143_, v___x_1147_);
v___x_1149_ = lean_nat_dec_lt(v_z_1145_, v___x_1148_);
if (v___x_1149_ == 0)
{
lean_object* v___x_1150_; lean_object* v___x_1151_; uint8_t v___x_1152_; 
lean_dec(v___x_1148_);
v___x_1150_ = lean_unsigned_to_nat(4u);
v___x_1151_ = l_BitVec_ofNat(v___x_1143_, v___x_1150_);
v___x_1152_ = lean_nat_dec_lt(v_z_1145_, v___x_1151_);
if (v___x_1152_ == 0)
{
lean_object* v___x_1153_; lean_object* v___x_1154_; uint8_t v___x_1155_; 
lean_dec(v___x_1151_);
v___x_1153_ = lean_unsigned_to_nat(5u);
v___x_1154_ = l_BitVec_ofNat(v___x_1143_, v___x_1153_);
v___x_1155_ = lean_nat_dec_lt(v_z_1145_, v___x_1154_);
if (v___x_1155_ == 0)
{
lean_object* v___x_1156_; lean_object* v___x_1157_; uint8_t v___x_1158_; 
lean_dec(v___x_1154_);
v___x_1156_ = lean_unsigned_to_nat(9u);
v___x_1157_ = l_BitVec_ofNat(v___x_1143_, v___x_1156_);
v___x_1158_ = lean_nat_dec_lt(v_z_1145_, v___x_1157_);
if (v___x_1158_ == 0)
{
lean_dec(v___x_1157_);
lean_inc(v___x_1144_);
return v___x_1144_;
}
else
{
return v___x_1157_;
}
}
else
{
return v___x_1154_;
}
}
else
{
return v___x_1151_;
}
}
else
{
return v___x_1148_;
}
}
else
{
lean_inc(v___x_1142_);
return v___x_1142_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_fig3__D2___lam__1___boxed(lean_object* v___x_1159_, lean_object* v___x_1160_, lean_object* v___x_1161_, lean_object* v_z_1162_){
_start:
{
lean_object* v_res_1163_; 
v_res_1163_ = lp_parametric_PLDIProofs_fig3__D2___lam__1(v___x_1159_, v___x_1160_, v___x_1161_, v_z_1162_);
lean_dec(v_z_1162_);
lean_dec(v___x_1161_);
lean_dec(v___x_1160_);
lean_dec(v___x_1159_);
return v_res_1163_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D2___closed__0(void){
_start:
{
lean_object* v___x_1164_; lean_object* v___x_1165_; lean_object* v___x_1166_; 
v___x_1164_ = lean_unsigned_to_nat(0u);
v___x_1165_ = lean_unsigned_to_nat(8u);
v___x_1166_ = l_BitVec_ofNat(v___x_1165_, v___x_1164_);
return v___x_1166_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D2___closed__1(void){
_start:
{
lean_object* v___x_1167_; lean_object* v___x_1168_; lean_object* v___x_1169_; lean_object* v___f_1170_; 
v___x_1167_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__0, &lp_parametric_PLDIProofs_fig3__D2___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__0);
v___x_1168_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1169_ = lean_unsigned_to_nat(8u);
v___f_1170_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_fig3__D2___lam__0___boxed), 4, 3);
lean_closure_set(v___f_1170_, 0, v___x_1169_);
lean_closure_set(v___f_1170_, 1, v___x_1168_);
lean_closure_set(v___f_1170_, 2, v___x_1167_);
return v___f_1170_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D2___closed__2(void){
_start:
{
lean_object* v___x_1171_; lean_object* v___x_1172_; lean_object* v___x_1173_; lean_object* v___f_1174_; 
v___x_1171_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1172_ = lean_unsigned_to_nat(8u);
v___x_1173_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__0, &lp_parametric_PLDIProofs_fig3__D2___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__0);
v___f_1174_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_fig3__D2___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1174_, 0, v___x_1173_);
lean_closure_set(v___f_1174_, 1, v___x_1172_);
lean_closure_set(v___f_1174_, 2, v___x_1171_);
return v___f_1174_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D2___closed__3(void){
_start:
{
lean_object* v___f_1175_; lean_object* v___f_1176_; lean_object* v___x_1177_; lean_object* v___x_1178_; lean_object* v___x_1179_; 
v___f_1175_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__2, &lp_parametric_PLDIProofs_fig3__D2___closed__2_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__2);
v___f_1176_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__1, &lp_parametric_PLDIProofs_fig3__D2___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__1);
v___x_1177_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D1___closed__1, &lp_parametric_PLDIProofs_fig3__D1___closed__1_once, _init_lp_parametric_PLDIProofs_fig3__D1___closed__1);
v___x_1178_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__0, &lp_parametric_PLDIProofs_fig3__D2___closed__0_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__0);
v___x_1179_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1179_, 0, v___x_1178_);
lean_ctor_set(v___x_1179_, 1, v___x_1177_);
lean_ctor_set(v___x_1179_, 2, v___f_1176_);
lean_ctor_set(v___x_1179_, 3, v___f_1175_);
return v___x_1179_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig3__D2(void){
_start:
{
lean_object* v___x_1180_; 
v___x_1180_ = lean_obj_once(&lp_parametric_PLDIProofs_fig3__D2___closed__3, &lp_parametric_PLDIProofs_fig3__D2___closed__3_once, _init_lp_parametric_PLDIProofs_fig3__D2___closed__3);
return v___x_1180_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_SInterval_crossesZero(lean_object* v_w_1181_, lean_object* v_I_1182_){
_start:
{
lean_object* v_smin_1183_; lean_object* v_smax_1184_; lean_object* v___x_1185_; lean_object* v___x_1186_; uint8_t v___x_1187_; 
v_smin_1183_ = lean_ctor_get(v_I_1182_, 0);
lean_inc(v_smin_1183_);
v_smax_1184_ = lean_ctor_get(v_I_1182_, 1);
lean_inc(v_smax_1184_);
lean_dec_ref(v_I_1182_);
v___x_1185_ = lean_unsigned_to_nat(0u);
v___x_1186_ = l_BitVec_ofNat(v_w_1181_, v___x_1185_);
lean_inc(v___x_1186_);
v___x_1187_ = l_BitVec_slt(v_w_1181_, v_smin_1183_, v___x_1186_);
if (v___x_1187_ == 0)
{
lean_dec(v___x_1186_);
lean_dec(v_smax_1184_);
return v___x_1187_;
}
else
{
uint8_t v___x_1188_; 
v___x_1188_ = l_BitVec_sle(v_w_1181_, v___x_1186_, v_smax_1184_);
return v___x_1188_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_SInterval_crossesZero___boxed(lean_object* v_w_1189_, lean_object* v_I_1190_){
_start:
{
uint8_t v_res_1191_; lean_object* v_r_1192_; 
v_res_1191_ = lp_parametric_PLDIProofs_SInterval_crossesZero(v_w_1189_, v_I_1190_);
lean_dec(v_w_1189_);
v_r_1192_ = lean_box(v_res_1191_);
return v_r_1192_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumHi(lean_object* v_w__lo_1193_, lean_object* v_w__hi_1194_, lean_object* v_t_1195_){
_start:
{
lean_object* v_v_1196_; lean_object* v_m_1197_; lean_object* v___x_1199_; uint8_t v_isShared_1200_; uint8_t v_isSharedCheck_1206_; 
v_v_1196_ = lean_ctor_get(v_t_1195_, 0);
v_m_1197_ = lean_ctor_get(v_t_1195_, 1);
v_isSharedCheck_1206_ = !lean_is_exclusive(v_t_1195_);
if (v_isSharedCheck_1206_ == 0)
{
v___x_1199_ = v_t_1195_;
v_isShared_1200_ = v_isSharedCheck_1206_;
goto v_resetjp_1198_;
}
else
{
lean_inc(v_m_1197_);
lean_inc(v_v_1196_);
lean_dec(v_t_1195_);
v___x_1199_ = lean_box(0);
v_isShared_1200_ = v_isSharedCheck_1206_;
goto v_resetjp_1198_;
}
v_resetjp_1198_:
{
lean_object* v___x_1201_; lean_object* v___x_1202_; lean_object* v___x_1204_; 
v___x_1201_ = l_BitVec_extractLsb_x27___redArg(v_w__lo_1193_, v_w__hi_1194_, v_v_1196_);
lean_dec(v_v_1196_);
v___x_1202_ = l_BitVec_extractLsb_x27___redArg(v_w__lo_1193_, v_w__hi_1194_, v_m_1197_);
lean_dec(v_m_1197_);
if (v_isShared_1200_ == 0)
{
lean_ctor_set(v___x_1199_, 1, v___x_1202_);
lean_ctor_set(v___x_1199_, 0, v___x_1201_);
v___x_1204_ = v___x_1199_;
goto v_reusejp_1203_;
}
else
{
lean_object* v_reuseFailAlloc_1205_; 
v_reuseFailAlloc_1205_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1205_, 0, v___x_1201_);
lean_ctor_set(v_reuseFailAlloc_1205_, 1, v___x_1202_);
v___x_1204_ = v_reuseFailAlloc_1205_;
goto v_reusejp_1203_;
}
v_reusejp_1203_:
{
return v___x_1204_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumHi___boxed(lean_object* v_w__lo_1207_, lean_object* v_w__hi_1208_, lean_object* v_t_1209_){
_start:
{
lean_object* v_res_1210_; 
v_res_1210_ = lp_parametric_PLDIProofs_tnumHi(v_w__lo_1207_, v_w__hi_1208_, v_t_1209_);
lean_dec(v_w__hi_1208_);
lean_dec(v_w__lo_1207_);
return v_res_1210_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___redArg(lean_object* v_w__lo_1211_, lean_object* v_t_1212_){
_start:
{
lean_object* v_v_1213_; lean_object* v_m_1214_; lean_object* v___x_1216_; uint8_t v_isShared_1217_; uint8_t v_isSharedCheck_1223_; 
v_v_1213_ = lean_ctor_get(v_t_1212_, 0);
v_m_1214_ = lean_ctor_get(v_t_1212_, 1);
v_isSharedCheck_1223_ = !lean_is_exclusive(v_t_1212_);
if (v_isSharedCheck_1223_ == 0)
{
v___x_1216_ = v_t_1212_;
v_isShared_1217_ = v_isSharedCheck_1223_;
goto v_resetjp_1215_;
}
else
{
lean_inc(v_m_1214_);
lean_inc(v_v_1213_);
lean_dec(v_t_1212_);
v___x_1216_ = lean_box(0);
v_isShared_1217_ = v_isSharedCheck_1223_;
goto v_resetjp_1215_;
}
v_resetjp_1215_:
{
lean_object* v___x_1218_; lean_object* v___x_1219_; lean_object* v___x_1221_; 
v___x_1218_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_1211_, v_v_1213_);
lean_dec(v_v_1213_);
v___x_1219_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_1211_, v_m_1214_);
lean_dec(v_m_1214_);
if (v_isShared_1217_ == 0)
{
lean_ctor_set(v___x_1216_, 1, v___x_1219_);
lean_ctor_set(v___x_1216_, 0, v___x_1218_);
v___x_1221_ = v___x_1216_;
goto v_reusejp_1220_;
}
else
{
lean_object* v_reuseFailAlloc_1222_; 
v_reuseFailAlloc_1222_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1222_, 0, v___x_1218_);
lean_ctor_set(v_reuseFailAlloc_1222_, 1, v___x_1219_);
v___x_1221_ = v_reuseFailAlloc_1222_;
goto v_reusejp_1220_;
}
v_reusejp_1220_:
{
return v___x_1221_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___redArg___boxed(lean_object* v_w__lo_1224_, lean_object* v_t_1225_){
_start:
{
lean_object* v_res_1226_; 
v_res_1226_ = lp_parametric_PLDIProofs_tnumLo___redArg(v_w__lo_1224_, v_t_1225_);
lean_dec(v_w__lo_1224_);
return v_res_1226_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo(lean_object* v_w__lo_1227_, lean_object* v_w__hi_1228_, lean_object* v_t_1229_){
_start:
{
lean_object* v___x_1230_; 
v___x_1230_ = lp_parametric_PLDIProofs_tnumLo___redArg(v_w__lo_1227_, v_t_1229_);
return v___x_1230_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumLo___boxed(lean_object* v_w__lo_1231_, lean_object* v_w__hi_1232_, lean_object* v_t_1233_){
_start:
{
lean_object* v_res_1234_; 
v_res_1234_ = lp_parametric_PLDIProofs_tnumLo(v_w__lo_1231_, v_w__hi_1232_, v_t_1233_);
lean_dec(v_w__hi_1232_);
lean_dec(v_w__lo_1231_);
return v_res_1234_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(lean_object* v_x_1235_, lean_object* v_x_1236_){
_start:
{
lean_object* v_kRange_1237_; lean_object* v_subRange_1238_; lean_object* v_kRange_1239_; lean_object* v_subRange_1240_; uint8_t v___x_1241_; 
v_kRange_1237_ = lean_ctor_get(v_x_1235_, 0);
v_subRange_1238_ = lean_ctor_get(v_x_1235_, 1);
v_kRange_1239_ = lean_ctor_get(v_x_1236_, 0);
v_subRange_1240_ = lean_ctor_get(v_x_1236_, 1);
v___x_1241_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_kRange_1237_, v_kRange_1239_);
if (v___x_1241_ == 0)
{
return v___x_1241_;
}
else
{
uint8_t v___x_1242_; 
v___x_1242_ = lp_parametric_PLDIProofs_instDecidableEqUInterval_decEq___redArg(v_subRange_1238_, v_subRange_1240_);
return v___x_1242_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg___boxed(lean_object* v_x_1243_, lean_object* v_x_1244_){
_start:
{
uint8_t v_res_1245_; lean_object* v_r_1246_; 
v_res_1245_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(v_x_1243_, v_x_1244_);
lean_dec_ref(v_x_1244_);
lean_dec_ref(v_x_1243_);
v_r_1246_ = lean_box(v_res_1245_);
return v_r_1246_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq(lean_object* v_w__lo_1247_, lean_object* v_w__hi_1248_, lean_object* v_x_1249_, lean_object* v_x_1250_){
_start:
{
uint8_t v___x_1251_; 
v___x_1251_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(v_x_1249_, v_x_1250_);
return v___x_1251_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___boxed(lean_object* v_w__lo_1252_, lean_object* v_w__hi_1253_, lean_object* v_x_1254_, lean_object* v_x_1255_){
_start:
{
uint8_t v_res_1256_; lean_object* v_r_1257_; 
v_res_1256_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq(v_w__lo_1252_, v_w__hi_1253_, v_x_1254_, v_x_1255_);
lean_dec_ref(v_x_1255_);
lean_dec_ref(v_x_1254_);
lean_dec(v_w__hi_1253_);
lean_dec(v_w__lo_1252_);
v_r_1257_ = lean_box(v_res_1256_);
return v_r_1257_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___redArg(lean_object* v_x_1258_, lean_object* v_x_1259_){
_start:
{
uint8_t v___x_1260_; 
v___x_1260_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(v_x_1258_, v_x_1259_);
return v___x_1260_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___redArg___boxed(lean_object* v_x_1261_, lean_object* v_x_1262_){
_start:
{
uint8_t v_res_1263_; lean_object* v_r_1264_; 
v_res_1263_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___redArg(v_x_1261_, v_x_1262_);
lean_dec_ref(v_x_1262_);
lean_dec_ref(v_x_1261_);
v_r_1264_ = lean_box(v_res_1263_);
return v_r_1264_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqSubspaceBox(lean_object* v_w__lo_1265_, lean_object* v_w__hi_1266_, lean_object* v_x_1267_, lean_object* v_x_1268_){
_start:
{
uint8_t v___x_1269_; 
v___x_1269_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox_decEq___redArg(v_x_1267_, v_x_1268_);
return v___x_1269_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqSubspaceBox___boxed(lean_object* v_w__lo_1270_, lean_object* v_w__hi_1271_, lean_object* v_x_1272_, lean_object* v_x_1273_){
_start:
{
uint8_t v_res_1274_; lean_object* v_r_1275_; 
v_res_1274_ = lp_parametric_PLDIProofs_instDecidableEqSubspaceBox(v_w__lo_1270_, v_w__hi_1271_, v_x_1272_, v_x_1273_);
lean_dec_ref(v_x_1273_);
lean_dec_ref(v_x_1272_);
lean_dec(v_w__hi_1271_);
lean_dec(v_w__lo_1270_);
v_r_1275_ = lean_box(v_res_1274_);
return v_r_1275_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4(void){
_start:
{
lean_object* v___x_1285_; lean_object* v___x_1286_; 
v___x_1285_ = lean_unsigned_to_nat(10u);
v___x_1286_ = lean_nat_to_int(v___x_1285_);
return v___x_1286_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_1290_; lean_object* v___x_1291_; 
v___x_1290_ = lean_unsigned_to_nat(12u);
v___x_1291_ = lean_nat_to_int(v___x_1290_);
return v___x_1291_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg(lean_object* v_w__lo_1292_, lean_object* v_w__hi_1293_, lean_object* v_x_1294_){
_start:
{
lean_object* v_kRange_1295_; lean_object* v_subRange_1296_; lean_object* v___x_1298_; uint8_t v_isShared_1299_; uint8_t v_isSharedCheck_1329_; 
v_kRange_1295_ = lean_ctor_get(v_x_1294_, 0);
v_subRange_1296_ = lean_ctor_get(v_x_1294_, 1);
v_isSharedCheck_1329_ = !lean_is_exclusive(v_x_1294_);
if (v_isSharedCheck_1329_ == 0)
{
v___x_1298_ = v_x_1294_;
v_isShared_1299_ = v_isSharedCheck_1329_;
goto v_resetjp_1297_;
}
else
{
lean_inc(v_subRange_1296_);
lean_inc(v_kRange_1295_);
lean_dec(v_x_1294_);
v___x_1298_ = lean_box(0);
v_isShared_1299_ = v_isSharedCheck_1329_;
goto v_resetjp_1297_;
}
v_resetjp_1297_:
{
lean_object* v___x_1300_; lean_object* v___x_1301_; lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1305_; 
v___x_1300_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__5));
v___x_1301_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__3));
v___x_1302_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4, &lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4_once, _init_lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__4);
v___x_1303_ = lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(v_w__hi_1293_, v_kRange_1295_);
if (v_isShared_1299_ == 0)
{
lean_ctor_set_tag(v___x_1298_, 4);
lean_ctor_set(v___x_1298_, 1, v___x_1303_);
lean_ctor_set(v___x_1298_, 0, v___x_1302_);
v___x_1305_ = v___x_1298_;
goto v_reusejp_1304_;
}
else
{
lean_object* v_reuseFailAlloc_1328_; 
v_reuseFailAlloc_1328_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1328_, 0, v___x_1302_);
lean_ctor_set(v_reuseFailAlloc_1328_, 1, v___x_1303_);
v___x_1305_ = v_reuseFailAlloc_1328_;
goto v_reusejp_1304_;
}
v_reusejp_1304_:
{
uint8_t v___x_1306_; lean_object* v___x_1307_; lean_object* v___x_1308_; lean_object* v___x_1309_; lean_object* v___x_1310_; lean_object* v___x_1311_; lean_object* v___x_1312_; lean_object* v___x_1313_; lean_object* v___x_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; lean_object* v___x_1317_; lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1327_; 
v___x_1306_ = 0;
v___x_1307_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1307_, 0, v___x_1305_);
lean_ctor_set_uint8(v___x_1307_, sizeof(void*)*1, v___x_1306_);
v___x_1308_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1308_, 0, v___x_1301_);
lean_ctor_set(v___x_1308_, 1, v___x_1307_);
v___x_1309_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__9));
v___x_1310_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1310_, 0, v___x_1308_);
lean_ctor_set(v___x_1310_, 1, v___x_1309_);
v___x_1311_ = lean_box(1);
v___x_1312_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1312_, 0, v___x_1310_);
lean_ctor_set(v___x_1312_, 1, v___x_1311_);
v___x_1313_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__6));
v___x_1314_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1314_, 0, v___x_1312_);
lean_ctor_set(v___x_1314_, 1, v___x_1313_);
v___x_1315_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1315_, 0, v___x_1314_);
lean_ctor_set(v___x_1315_, 1, v___x_1300_);
v___x_1316_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7, &lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7_once, _init_lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg___closed__7);
v___x_1317_ = lp_parametric_PLDIProofs_instReprUInterval_repr___redArg(v_w__lo_1292_, v_subRange_1296_);
v___x_1318_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1318_, 0, v___x_1316_);
lean_ctor_set(v___x_1318_, 1, v___x_1317_);
v___x_1319_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1319_, 0, v___x_1318_);
lean_ctor_set_uint8(v___x_1319_, sizeof(void*)*1, v___x_1306_);
v___x_1320_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1320_, 0, v___x_1315_);
lean_ctor_set(v___x_1320_, 1, v___x_1319_);
v___x_1321_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14, &lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14_once, _init_lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__14);
v___x_1322_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__15));
v___x_1323_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1323_, 0, v___x_1322_);
lean_ctor_set(v___x_1323_, 1, v___x_1320_);
v___x_1324_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprUInterval_repr___redArg___closed__16));
v___x_1325_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_1325_, 0, v___x_1323_);
lean_ctor_set(v___x_1325_, 1, v___x_1324_);
v___x_1326_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1326_, 0, v___x_1321_);
lean_ctor_set(v___x_1326_, 1, v___x_1325_);
v___x_1327_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1327_, 0, v___x_1326_);
lean_ctor_set_uint8(v___x_1327_, sizeof(void*)*1, v___x_1306_);
return v___x_1327_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr(lean_object* v_w__lo_1330_, lean_object* v_w__hi_1331_, lean_object* v_x_1332_, lean_object* v_prec_1333_){
_start:
{
lean_object* v___x_1334_; 
v___x_1334_ = lp_parametric_PLDIProofs_instReprSubspaceBox_repr___redArg(v_w__lo_1330_, v_w__hi_1331_, v_x_1332_);
return v___x_1334_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox_repr___boxed(lean_object* v_w__lo_1335_, lean_object* v_w__hi_1336_, lean_object* v_x_1337_, lean_object* v_prec_1338_){
_start:
{
lean_object* v_res_1339_; 
v_res_1339_ = lp_parametric_PLDIProofs_instReprSubspaceBox_repr(v_w__lo_1335_, v_w__hi_1336_, v_x_1337_, v_prec_1338_);
lean_dec(v_prec_1338_);
return v_res_1339_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprSubspaceBox(lean_object* v_w__lo_1340_, lean_object* v_w__hi_1341_){
_start:
{
lean_object* v___x_1342_; 
v___x_1342_ = lean_alloc_closure((void*)(lp_parametric_PLDIProofs_instReprSubspaceBox_repr___boxed), 4, 2);
lean_closure_set(v___x_1342_, 0, v_w__lo_1340_);
lean_closure_set(v___x_1342_, 1, v_w__hi_1341_);
return v___x_1342_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_projectInterval(lean_object* v_w__lo_1343_, lean_object* v_w__hi_1344_, lean_object* v_I_1345_){
_start:
{
lean_object* v_min_1346_; lean_object* v_max_1347_; lean_object* v___x_1349_; uint8_t v_isShared_1350_; uint8_t v_isSharedCheck_1390_; 
v_min_1346_ = lean_ctor_get(v_I_1345_, 0);
v_max_1347_ = lean_ctor_get(v_I_1345_, 1);
v_isSharedCheck_1390_ = !lean_is_exclusive(v_I_1345_);
if (v_isSharedCheck_1390_ == 0)
{
v___x_1349_ = v_I_1345_;
v_isShared_1350_ = v_isSharedCheck_1390_;
goto v_resetjp_1348_;
}
else
{
lean_inc(v_max_1347_);
lean_inc(v_min_1346_);
lean_dec(v_I_1345_);
v___x_1349_ = lean_box(0);
v_isShared_1350_ = v_isSharedCheck_1390_;
goto v_resetjp_1348_;
}
v_resetjp_1348_:
{
lean_object* v_k__start_1351_; lean_object* v_r__start_1352_; lean_object* v_k__end_1353_; lean_object* v_r__end_1354_; uint8_t v___x_1355_; 
v_k__start_1351_ = l_BitVec_extractLsb_x27___redArg(v_w__lo_1343_, v_w__hi_1344_, v_min_1346_);
v_r__start_1352_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_1343_, v_min_1346_);
lean_dec(v_min_1346_);
v_k__end_1353_ = l_BitVec_extractLsb_x27___redArg(v_w__lo_1343_, v_w__hi_1344_, v_max_1347_);
v_r__end_1354_ = lp_parametric_PLDIProofs_loSlice___redArg(v_w__lo_1343_, v_max_1347_);
lean_dec(v_max_1347_);
v___x_1355_ = lean_nat_dec_eq(v_k__start_1351_, v_k__end_1353_);
if (v___x_1355_ == 0)
{
lean_object* v___x_1357_; 
lean_inc_n(v_k__start_1351_, 2);
if (v_isShared_1350_ == 0)
{
lean_ctor_set(v___x_1349_, 1, v_k__start_1351_);
lean_ctor_set(v___x_1349_, 0, v_k__start_1351_);
v___x_1357_ = v___x_1349_;
goto v_reusejp_1356_;
}
else
{
lean_object* v_reuseFailAlloc_1382_; 
v_reuseFailAlloc_1382_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1382_, 0, v_k__start_1351_);
lean_ctor_set(v_reuseFailAlloc_1382_, 1, v_k__start_1351_);
v___x_1357_ = v_reuseFailAlloc_1382_;
goto v_reusejp_1356_;
}
v_reusejp_1356_:
{
lean_object* v___x_1358_; lean_object* v___x_1359_; lean_object* v_b__head_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v_b__tail_1365_; lean_object* v___x_1366_; lean_object* v___x_1367_; uint8_t v___x_1368_; 
v___x_1358_ = l_BitVec_allOnes(v_w__lo_1343_);
lean_inc(v___x_1358_);
v___x_1359_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1359_, 0, v_r__start_1352_);
lean_ctor_set(v___x_1359_, 1, v___x_1358_);
v_b__head_1360_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_b__head_1360_, 0, v___x_1357_);
lean_ctor_set(v_b__head_1360_, 1, v___x_1359_);
lean_inc_n(v_k__end_1353_, 2);
v___x_1361_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1361_, 0, v_k__end_1353_);
lean_ctor_set(v___x_1361_, 1, v_k__end_1353_);
v___x_1362_ = lean_unsigned_to_nat(0u);
v___x_1363_ = l_BitVec_ofNat(v_w__lo_1343_, v___x_1362_);
lean_inc(v___x_1363_);
v___x_1364_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1364_, 0, v___x_1363_);
lean_ctor_set(v___x_1364_, 1, v_r__end_1354_);
v_b__tail_1365_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_b__tail_1365_, 0, v___x_1361_);
lean_ctor_set(v_b__tail_1365_, 1, v___x_1364_);
v___x_1366_ = lean_unsigned_to_nat(1u);
v___x_1367_ = lean_nat_add(v_k__start_1351_, v___x_1366_);
lean_dec(v_k__start_1351_);
v___x_1368_ = lean_nat_dec_lt(v___x_1367_, v_k__end_1353_);
if (v___x_1368_ == 0)
{
lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; 
lean_dec(v___x_1367_);
lean_dec(v___x_1363_);
lean_dec(v___x_1358_);
lean_dec(v_k__end_1353_);
v___x_1369_ = lean_box(0);
v___x_1370_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1370_, 0, v_b__tail_1365_);
lean_ctor_set(v___x_1370_, 1, v___x_1369_);
v___x_1371_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1371_, 0, v_b__head_1360_);
lean_ctor_set(v___x_1371_, 1, v___x_1370_);
return v___x_1371_;
}
else
{
lean_object* v___x_1372_; lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; lean_object* v_b__mid_1377_; lean_object* v___x_1378_; lean_object* v___x_1379_; lean_object* v___x_1380_; lean_object* v___x_1381_; 
v___x_1372_ = l_BitVec_ofNat(v_w__hi_1344_, v___x_1367_);
lean_dec(v___x_1367_);
v___x_1373_ = lean_nat_sub(v_k__end_1353_, v___x_1366_);
lean_dec(v_k__end_1353_);
v___x_1374_ = l_BitVec_ofNat(v_w__hi_1344_, v___x_1373_);
lean_dec(v___x_1373_);
v___x_1375_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1375_, 0, v___x_1372_);
lean_ctor_set(v___x_1375_, 1, v___x_1374_);
v___x_1376_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1376_, 0, v___x_1363_);
lean_ctor_set(v___x_1376_, 1, v___x_1358_);
v_b__mid_1377_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_b__mid_1377_, 0, v___x_1375_);
lean_ctor_set(v_b__mid_1377_, 1, v___x_1376_);
v___x_1378_ = lean_box(0);
v___x_1379_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1379_, 0, v_b__tail_1365_);
lean_ctor_set(v___x_1379_, 1, v___x_1378_);
v___x_1380_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1380_, 0, v_b__mid_1377_);
lean_ctor_set(v___x_1380_, 1, v___x_1379_);
v___x_1381_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1381_, 0, v_b__head_1360_);
lean_ctor_set(v___x_1381_, 1, v___x_1380_);
return v___x_1381_;
}
}
}
else
{
lean_object* v___x_1384_; 
lean_dec(v_k__end_1353_);
lean_inc(v_k__start_1351_);
if (v_isShared_1350_ == 0)
{
lean_ctor_set(v___x_1349_, 1, v_k__start_1351_);
lean_ctor_set(v___x_1349_, 0, v_k__start_1351_);
v___x_1384_ = v___x_1349_;
goto v_reusejp_1383_;
}
else
{
lean_object* v_reuseFailAlloc_1389_; 
v_reuseFailAlloc_1389_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1389_, 0, v_k__start_1351_);
lean_ctor_set(v_reuseFailAlloc_1389_, 1, v_k__start_1351_);
v___x_1384_ = v_reuseFailAlloc_1389_;
goto v_reusejp_1383_;
}
v_reusejp_1383_:
{
lean_object* v___x_1385_; lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1388_; 
v___x_1385_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1385_, 0, v_r__start_1352_);
lean_ctor_set(v___x_1385_, 1, v_r__end_1354_);
v___x_1386_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1386_, 0, v___x_1384_);
lean_ctor_set(v___x_1386_, 1, v___x_1385_);
v___x_1387_ = lean_box(0);
v___x_1388_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1388_, 0, v___x_1386_);
lean_ctor_set(v___x_1388_, 1, v___x_1387_);
return v___x_1388_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_projectInterval___boxed(lean_object* v_w__lo_1391_, lean_object* v_w__hi_1392_, lean_object* v_I_1393_){
_start:
{
lean_object* v_res_1394_; 
v_res_1394_ = lp_parametric_PLDIProofs_projectInterval(v_w__lo_1391_, v_w__hi_1392_, v_I_1393_);
lean_dec(v_w__hi_1392_);
lean_dec(v_w__lo_1391_);
return v_res_1394_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU___redArg(lean_object* v_a_1395_, lean_object* v_b_1396_){
_start:
{
lean_object* v___y_1398_; lean_object* v___y_1399_; lean_object* v_min_1404_; lean_object* v_max_1405_; lean_object* v_min_1406_; lean_object* v_max_1407_; lean_object* v___y_1409_; uint8_t v___x_1411_; 
v_min_1404_ = lean_ctor_get(v_a_1395_, 0);
lean_inc(v_min_1404_);
v_max_1405_ = lean_ctor_get(v_a_1395_, 1);
lean_inc(v_max_1405_);
lean_dec_ref(v_a_1395_);
v_min_1406_ = lean_ctor_get(v_b_1396_, 0);
lean_inc(v_min_1406_);
v_max_1407_ = lean_ctor_get(v_b_1396_, 1);
lean_inc(v_max_1407_);
lean_dec_ref(v_b_1396_);
v___x_1411_ = lean_nat_dec_le(v_min_1404_, v_min_1406_);
if (v___x_1411_ == 0)
{
lean_dec(v_min_1406_);
v___y_1409_ = v_min_1404_;
goto v___jp_1408_;
}
else
{
lean_dec(v_min_1404_);
v___y_1409_ = v_min_1406_;
goto v___jp_1408_;
}
v___jp_1397_:
{
uint8_t v___x_1400_; 
v___x_1400_ = lean_nat_dec_le(v___y_1398_, v___y_1399_);
if (v___x_1400_ == 0)
{
lean_object* v___x_1401_; 
lean_dec(v___y_1399_);
lean_dec(v___y_1398_);
v___x_1401_ = lean_box(0);
return v___x_1401_;
}
else
{
lean_object* v___x_1402_; lean_object* v___x_1403_; 
v___x_1402_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1402_, 0, v___y_1398_);
lean_ctor_set(v___x_1402_, 1, v___y_1399_);
v___x_1403_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1403_, 0, v___x_1402_);
return v___x_1403_;
}
}
v___jp_1408_:
{
uint8_t v___x_1410_; 
v___x_1410_ = lean_nat_dec_le(v_max_1405_, v_max_1407_);
if (v___x_1410_ == 0)
{
lean_dec(v_max_1405_);
v___y_1398_ = v___y_1409_;
v___y_1399_ = v_max_1407_;
goto v___jp_1397_;
}
else
{
lean_dec(v_max_1407_);
v___y_1398_ = v___y_1409_;
v___y_1399_ = v_max_1405_;
goto v___jp_1397_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU(lean_object* v_w_1412_, lean_object* v_a_1413_, lean_object* v_b_1414_){
_start:
{
lean_object* v___x_1415_; 
v___x_1415_ = lp_parametric_PLDIProofs_intersectU___redArg(v_a_1413_, v_b_1414_);
return v___x_1415_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_intersectU___boxed(lean_object* v_w_1416_, lean_object* v_a_1417_, lean_object* v_b_1418_){
_start:
{
lean_object* v_res_1419_; 
v_res_1419_ = lp_parametric_PLDIProofs_intersectU(v_w_1416_, v_a_1417_, v_b_1418_);
lean_dec(v_w_1416_);
return v_res_1419_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___redArg(lean_object* v_u_1420_, lean_object* v_a_1421_, lean_object* v_a_1422_){
_start:
{
if (lean_obj_tag(v_a_1421_) == 0)
{
lean_object* v___x_1423_; 
lean_dec_ref(v_u_1420_);
v___x_1423_ = lean_array_to_list(v_a_1422_);
return v___x_1423_;
}
else
{
lean_object* v_head_1424_; lean_object* v_tail_1425_; lean_object* v___x_1426_; 
v_head_1424_ = lean_ctor_get(v_a_1421_, 0);
lean_inc(v_head_1424_);
v_tail_1425_ = lean_ctor_get(v_a_1421_, 1);
lean_inc(v_tail_1425_);
lean_dec_ref_known(v_a_1421_, 2);
lean_inc_ref(v_u_1420_);
v___x_1426_ = lp_parametric_PLDIProofs_intersectU___redArg(v_u_1420_, v_head_1424_);
if (lean_obj_tag(v___x_1426_) == 0)
{
v_a_1421_ = v_tail_1425_;
goto _start;
}
else
{
lean_object* v_val_1428_; lean_object* v___x_1429_; 
v_val_1428_ = lean_ctor_get(v___x_1426_, 0);
lean_inc(v_val_1428_);
lean_dec_ref_known(v___x_1426_, 1);
v___x_1429_ = lean_array_push(v_a_1422_, v_val_1428_);
v_a_1421_ = v_tail_1425_;
v_a_1422_ = v___x_1429_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__width(lean_object* v_w_1433_, lean_object* v_u_1434_, lean_object* v_s_1435_){
_start:
{
lean_object* v___y_1437_; uint8_t v___x_1440_; 
lean_inc_ref(v_s_1435_);
v___x_1440_ = lp_parametric_PLDIProofs_SInterval_crossesZero(v_w_1433_, v_s_1435_);
if (v___x_1440_ == 0)
{
lean_object* v_smin_1441_; lean_object* v_smax_1442_; lean_object* v___x_1444_; uint8_t v_isShared_1445_; uint8_t v_isSharedCheck_1451_; 
v_smin_1441_ = lean_ctor_get(v_s_1435_, 0);
v_smax_1442_ = lean_ctor_get(v_s_1435_, 1);
v_isSharedCheck_1451_ = !lean_is_exclusive(v_s_1435_);
if (v_isSharedCheck_1451_ == 0)
{
v___x_1444_ = v_s_1435_;
v_isShared_1445_ = v_isSharedCheck_1451_;
goto v_resetjp_1443_;
}
else
{
lean_inc(v_smax_1442_);
lean_inc(v_smin_1441_);
lean_dec(v_s_1435_);
v___x_1444_ = lean_box(0);
v_isShared_1445_ = v_isSharedCheck_1451_;
goto v_resetjp_1443_;
}
v_resetjp_1443_:
{
lean_object* v___x_1447_; 
if (v_isShared_1445_ == 0)
{
v___x_1447_ = v___x_1444_;
goto v_reusejp_1446_;
}
else
{
lean_object* v_reuseFailAlloc_1450_; 
v_reuseFailAlloc_1450_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1450_, 0, v_smin_1441_);
lean_ctor_set(v_reuseFailAlloc_1450_, 1, v_smax_1442_);
v___x_1447_ = v_reuseFailAlloc_1450_;
goto v_reusejp_1446_;
}
v_reusejp_1446_:
{
lean_object* v___x_1448_; lean_object* v___x_1449_; 
v___x_1448_ = lean_box(0);
v___x_1449_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1449_, 0, v___x_1447_);
lean_ctor_set(v___x_1449_, 1, v___x_1448_);
v___y_1437_ = v___x_1449_;
goto v___jp_1436_;
}
}
}
else
{
lean_object* v_smin_1452_; lean_object* v_smax_1453_; lean_object* v___x_1455_; uint8_t v_isShared_1456_; uint8_t v_isSharedCheck_1467_; 
v_smin_1452_ = lean_ctor_get(v_s_1435_, 0);
v_smax_1453_ = lean_ctor_get(v_s_1435_, 1);
v_isSharedCheck_1467_ = !lean_is_exclusive(v_s_1435_);
if (v_isSharedCheck_1467_ == 0)
{
v___x_1455_ = v_s_1435_;
v_isShared_1456_ = v_isSharedCheck_1467_;
goto v_resetjp_1454_;
}
else
{
lean_inc(v_smax_1453_);
lean_inc(v_smin_1452_);
lean_dec(v_s_1435_);
v___x_1455_ = lean_box(0);
v_isShared_1456_ = v_isSharedCheck_1467_;
goto v_resetjp_1454_;
}
v_resetjp_1454_:
{
lean_object* v___x_1457_; lean_object* v___x_1458_; lean_object* v___x_1460_; 
v___x_1457_ = lean_unsigned_to_nat(0u);
v___x_1458_ = l_BitVec_ofNat(v_w_1433_, v___x_1457_);
if (v_isShared_1456_ == 0)
{
lean_ctor_set(v___x_1455_, 0, v___x_1458_);
v___x_1460_ = v___x_1455_;
goto v_reusejp_1459_;
}
else
{
lean_object* v_reuseFailAlloc_1466_; 
v_reuseFailAlloc_1466_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1466_, 0, v___x_1458_);
lean_ctor_set(v_reuseFailAlloc_1466_, 1, v_smax_1453_);
v___x_1460_ = v_reuseFailAlloc_1466_;
goto v_reusejp_1459_;
}
v_reusejp_1459_:
{
lean_object* v___x_1461_; lean_object* v___x_1462_; lean_object* v___x_1463_; lean_object* v___x_1464_; lean_object* v___x_1465_; 
v___x_1461_ = l_BitVec_allOnes(v_w_1433_);
v___x_1462_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1462_, 0, v_smin_1452_);
lean_ctor_set(v___x_1462_, 1, v___x_1461_);
v___x_1463_ = lean_box(0);
v___x_1464_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1464_, 0, v___x_1462_);
lean_ctor_set(v___x_1464_, 1, v___x_1463_);
v___x_1465_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1465_, 0, v___x_1460_);
lean_ctor_set(v___x_1465_, 1, v___x_1464_);
v___y_1437_ = v___x_1465_;
goto v___jp_1436_;
}
}
}
v___jp_1436_:
{
lean_object* v___x_1438_; lean_object* v___x_1439_; 
v___x_1438_ = ((lean_object*)(lp_parametric_PLDIProofs_stage1__width___closed__0));
v___x_1439_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___redArg(v_u_1434_, v___y_1437_, v___x_1438_);
return v___x_1439_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__width___boxed(lean_object* v_w_1468_, lean_object* v_u_1469_, lean_object* v_s_1470_){
_start:
{
lean_object* v_res_1471_; 
v_res_1471_ = lp_parametric_PLDIProofs_stage1__width(v_w_1468_, v_u_1469_, v_s_1470_);
lean_dec(v_w_1468_);
return v_res_1471_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0(lean_object* v_w_1472_, lean_object* v_u_1473_, lean_object* v_a_1474_, lean_object* v_a_1475_){
_start:
{
lean_object* v___x_1476_; 
v___x_1476_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___redArg(v_u_1473_, v_a_1474_, v_a_1475_);
return v___x_1476_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0___boxed(lean_object* v_w_1477_, lean_object* v_u_1478_, lean_object* v_a_1479_, lean_object* v_a_1480_){
_start:
{
lean_object* v_res_1481_; 
v_res_1481_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage1__width_spec__0(v_w_1477_, v_u_1478_, v_a_1479_, v_a_1480_);
lean_dec(v_w_1477_);
return v_res_1481_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__full(lean_object* v_w__lo_1482_, lean_object* v_w__hi_1483_, lean_object* v_r_1484_){
_start:
{
lean_object* v_u64_1485_; lean_object* v_s64_1486_; lean_object* v___x_1487_; lean_object* v___x_1488_; 
v_u64_1485_ = lean_ctor_get(v_r_1484_, 0);
lean_inc_ref(v_u64_1485_);
v_s64_1486_ = lean_ctor_get(v_r_1484_, 1);
lean_inc_ref(v_s64_1486_);
lean_dec_ref(v_r_1484_);
v___x_1487_ = lean_nat_add(v_w__lo_1482_, v_w__hi_1483_);
v___x_1488_ = lp_parametric_PLDIProofs_stage1__width(v___x_1487_, v_u64_1485_, v_s64_1486_);
lean_dec(v___x_1487_);
return v___x_1488_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__full___boxed(lean_object* v_w__lo_1489_, lean_object* v_w__hi_1490_, lean_object* v_r_1491_){
_start:
{
lean_object* v_res_1492_; 
v_res_1492_ = lp_parametric_PLDIProofs_stage1__full(v_w__lo_1489_, v_w__hi_1490_, v_r_1491_);
lean_dec(v_w__hi_1490_);
lean_dec(v_w__lo_1489_);
return v_res_1492_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___redArg(lean_object* v_w__lo_1493_, lean_object* v_r_1494_){
_start:
{
lean_object* v_u32_1495_; lean_object* v_s32_1496_; lean_object* v___x_1497_; 
v_u32_1495_ = lean_ctor_get(v_r_1494_, 2);
lean_inc_ref(v_u32_1495_);
v_s32_1496_ = lean_ctor_get(v_r_1494_, 3);
lean_inc_ref(v_s32_1496_);
lean_dec_ref(v_r_1494_);
v___x_1497_ = lp_parametric_PLDIProofs_stage1__width(v_w__lo_1493_, v_u32_1495_, v_s32_1496_);
return v___x_1497_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___redArg___boxed(lean_object* v_w__lo_1498_, lean_object* v_r_1499_){
_start:
{
lean_object* v_res_1500_; 
v_res_1500_ = lp_parametric_PLDIProofs_stage1__sub___redArg(v_w__lo_1498_, v_r_1499_);
lean_dec(v_w__lo_1498_);
return v_res_1500_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub(lean_object* v_w__lo_1501_, lean_object* v_w__hi_1502_, lean_object* v_r_1503_){
_start:
{
lean_object* v___x_1504_; 
v___x_1504_ = lp_parametric_PLDIProofs_stage1__sub___redArg(v_w__lo_1501_, v_r_1503_);
return v___x_1504_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage1__sub___boxed(lean_object* v_w__lo_1505_, lean_object* v_w__hi_1506_, lean_object* v_r_1507_){
_start:
{
lean_object* v_res_1508_; 
v_res_1508_ = lp_parametric_PLDIProofs_stage1__sub(v_w__lo_1505_, v_w__hi_1506_, v_r_1507_);
lean_dec(v_w__hi_1506_);
lean_dec(v_w__lo_1505_);
return v_res_1508_;
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0(lean_object* v_w__lo_1509_, lean_object* v_w__hi_1510_, lean_object* v_a_1511_, lean_object* v_a_1512_){
_start:
{
if (lean_obj_tag(v_a_1511_) == 0)
{
lean_object* v___x_1513_; 
v___x_1513_ = lean_array_to_list(v_a_1512_);
return v___x_1513_;
}
else
{
lean_object* v_head_1514_; lean_object* v_tail_1515_; lean_object* v___x_1516_; lean_object* v___x_1517_; 
v_head_1514_ = lean_ctor_get(v_a_1511_, 0);
lean_inc(v_head_1514_);
v_tail_1515_ = lean_ctor_get(v_a_1511_, 1);
lean_inc(v_tail_1515_);
lean_dec_ref_known(v_a_1511_, 2);
v___x_1516_ = lp_parametric_PLDIProofs_projectInterval(v_w__lo_1509_, v_w__hi_1510_, v_head_1514_);
v___x_1517_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_1512_, v___x_1516_);
v_a_1511_ = v_tail_1515_;
v_a_1512_ = v___x_1517_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0___boxed(lean_object* v_w__lo_1519_, lean_object* v_w__hi_1520_, lean_object* v_a_1521_, lean_object* v_a_1522_){
_start:
{
lean_object* v_res_1523_; 
v_res_1523_ = lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0(v_w__lo_1519_, v_w__hi_1520_, v_a_1521_, v_a_1522_);
lean_dec(v_w__hi_1520_);
lean_dec(v_w__lo_1519_);
return v_res_1523_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__project(lean_object* v_w__lo_1526_, lean_object* v_w__hi_1527_, lean_object* v_r_1528_){
_start:
{
lean_object* v___x_1529_; lean_object* v___x_1530_; lean_object* v___x_1531_; 
v___x_1529_ = lp_parametric_PLDIProofs_stage1__full(v_w__lo_1526_, v_w__hi_1527_, v_r_1528_);
v___x_1530_ = ((lean_object*)(lp_parametric_PLDIProofs_stage2__project___closed__0));
v___x_1531_ = lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__project_spec__0(v_w__lo_1526_, v_w__hi_1527_, v___x_1529_, v___x_1530_);
return v___x_1531_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__project___boxed(lean_object* v_w__lo_1532_, lean_object* v_w__hi_1533_, lean_object* v_r_1534_){
_start:
{
lean_object* v_res_1535_; 
v_res_1535_ = lp_parametric_PLDIProofs_stage2__project(v_w__lo_1532_, v_w__hi_1533_, v_r_1534_);
lean_dec(v_w__hi_1533_);
lean_dec(v_w__lo_1532_);
return v_res_1535_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub___redArg(lean_object* v_B_1536_, lean_object* v_J_1537_){
_start:
{
lean_object* v_kRange_1538_; lean_object* v_subRange_1539_; lean_object* v___x_1541_; uint8_t v_isShared_1542_; uint8_t v_isSharedCheck_1556_; 
v_kRange_1538_ = lean_ctor_get(v_B_1536_, 0);
v_subRange_1539_ = lean_ctor_get(v_B_1536_, 1);
v_isSharedCheck_1556_ = !lean_is_exclusive(v_B_1536_);
if (v_isSharedCheck_1556_ == 0)
{
v___x_1541_ = v_B_1536_;
v_isShared_1542_ = v_isSharedCheck_1556_;
goto v_resetjp_1540_;
}
else
{
lean_inc(v_subRange_1539_);
lean_inc(v_kRange_1538_);
lean_dec(v_B_1536_);
v___x_1541_ = lean_box(0);
v_isShared_1542_ = v_isSharedCheck_1556_;
goto v_resetjp_1540_;
}
v_resetjp_1540_:
{
lean_object* v___x_1543_; 
v___x_1543_ = lp_parametric_PLDIProofs_intersectU___redArg(v_subRange_1539_, v_J_1537_);
if (lean_obj_tag(v___x_1543_) == 0)
{
lean_object* v___x_1544_; 
lean_del_object(v___x_1541_);
lean_dec_ref(v_kRange_1538_);
v___x_1544_ = lean_box(0);
return v___x_1544_;
}
else
{
lean_object* v_val_1545_; lean_object* v___x_1547_; uint8_t v_isShared_1548_; uint8_t v_isSharedCheck_1555_; 
v_val_1545_ = lean_ctor_get(v___x_1543_, 0);
v_isSharedCheck_1555_ = !lean_is_exclusive(v___x_1543_);
if (v_isSharedCheck_1555_ == 0)
{
v___x_1547_ = v___x_1543_;
v_isShared_1548_ = v_isSharedCheck_1555_;
goto v_resetjp_1546_;
}
else
{
lean_inc(v_val_1545_);
lean_dec(v___x_1543_);
v___x_1547_ = lean_box(0);
v_isShared_1548_ = v_isSharedCheck_1555_;
goto v_resetjp_1546_;
}
v_resetjp_1546_:
{
lean_object* v___x_1550_; 
if (v_isShared_1542_ == 0)
{
lean_ctor_set(v___x_1541_, 1, v_val_1545_);
v___x_1550_ = v___x_1541_;
goto v_reusejp_1549_;
}
else
{
lean_object* v_reuseFailAlloc_1554_; 
v_reuseFailAlloc_1554_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1554_, 0, v_kRange_1538_);
lean_ctor_set(v_reuseFailAlloc_1554_, 1, v_val_1545_);
v___x_1550_ = v_reuseFailAlloc_1554_;
goto v_reusejp_1549_;
}
v_reusejp_1549_:
{
lean_object* v___x_1552_; 
if (v_isShared_1548_ == 0)
{
lean_ctor_set(v___x_1547_, 0, v___x_1550_);
v___x_1552_ = v___x_1547_;
goto v_reusejp_1551_;
}
else
{
lean_object* v_reuseFailAlloc_1553_; 
v_reuseFailAlloc_1553_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1553_, 0, v___x_1550_);
v___x_1552_ = v_reuseFailAlloc_1553_;
goto v_reusejp_1551_;
}
v_reusejp_1551_:
{
return v___x_1552_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub(lean_object* v_w__lo_1557_, lean_object* v_w__hi_1558_, lean_object* v_B_1559_, lean_object* v_J_1560_){
_start:
{
lean_object* v___x_1561_; 
v___x_1561_ = lp_parametric_PLDIProofs_narrowBoxWithSub___redArg(v_B_1559_, v_J_1560_);
return v___x_1561_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_narrowBoxWithSub___boxed(lean_object* v_w__lo_1562_, lean_object* v_w__hi_1563_, lean_object* v_B_1564_, lean_object* v_J_1565_){
_start:
{
lean_object* v_res_1566_; 
v_res_1566_ = lp_parametric_PLDIProofs_narrowBoxWithSub(v_w__lo_1562_, v_w__hi_1563_, v_B_1564_, v_J_1565_);
lean_dec(v_w__hi_1563_);
lean_dec(v_w__lo_1562_);
return v_res_1566_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___redArg(lean_object* v_B_1567_, lean_object* v_a_1568_, lean_object* v_a_1569_){
_start:
{
if (lean_obj_tag(v_a_1568_) == 0)
{
lean_object* v___x_1570_; 
lean_dec_ref(v_B_1567_);
v___x_1570_ = lean_array_to_list(v_a_1569_);
return v___x_1570_;
}
else
{
lean_object* v_head_1571_; lean_object* v_tail_1572_; lean_object* v___x_1573_; 
v_head_1571_ = lean_ctor_get(v_a_1568_, 0);
lean_inc(v_head_1571_);
v_tail_1572_ = lean_ctor_get(v_a_1568_, 1);
lean_inc(v_tail_1572_);
lean_dec_ref_known(v_a_1568_, 2);
lean_inc_ref(v_B_1567_);
v___x_1573_ = lp_parametric_PLDIProofs_narrowBoxWithSub___redArg(v_B_1567_, v_head_1571_);
if (lean_obj_tag(v___x_1573_) == 0)
{
v_a_1568_ = v_tail_1572_;
goto _start;
}
else
{
lean_object* v_val_1575_; lean_object* v___x_1576_; 
v_val_1575_ = lean_ctor_get(v___x_1573_, 0);
lean_inc(v_val_1575_);
lean_dec_ref_known(v___x_1573_, 1);
v___x_1576_ = lean_array_push(v_a_1569_, v_val_1575_);
v_a_1568_ = v_tail_1572_;
v_a_1569_ = v___x_1576_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1(lean_object* v_w__lo_1578_, lean_object* v_w__hi_1579_, lean_object* v_r_1580_, lean_object* v_a_1581_, lean_object* v_a_1582_){
_start:
{
if (lean_obj_tag(v_a_1581_) == 0)
{
lean_object* v___x_1583_; 
lean_dec_ref(v_r_1580_);
v___x_1583_ = lean_array_to_list(v_a_1582_);
return v___x_1583_;
}
else
{
lean_object* v_head_1584_; lean_object* v_tail_1585_; lean_object* v___x_1586_; lean_object* v___x_1587_; lean_object* v___x_1588_; lean_object* v___x_1589_; 
v_head_1584_ = lean_ctor_get(v_a_1581_, 0);
lean_inc(v_head_1584_);
v_tail_1585_ = lean_ctor_get(v_a_1581_, 1);
lean_inc(v_tail_1585_);
lean_dec_ref_known(v_a_1581_, 2);
lean_inc_ref(v_r_1580_);
v___x_1586_ = lp_parametric_PLDIProofs_stage1__sub___redArg(v_w__lo_1578_, v_r_1580_);
v___x_1587_ = ((lean_object*)(lp_parametric_PLDIProofs_stage2__project___closed__0));
v___x_1588_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___redArg(v_head_1584_, v___x_1586_, v___x_1587_);
v___x_1589_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_1582_, v___x_1588_);
v_a_1581_ = v_tail_1585_;
v_a_1582_ = v___x_1589_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1___boxed(lean_object* v_w__lo_1591_, lean_object* v_w__hi_1592_, lean_object* v_r_1593_, lean_object* v_a_1594_, lean_object* v_a_1595_){
_start:
{
lean_object* v_res_1596_; 
v_res_1596_ = lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1(v_w__lo_1591_, v_w__hi_1592_, v_r_1593_, v_a_1594_, v_a_1595_);
lean_dec(v_w__hi_1592_);
lean_dec(v_w__lo_1591_);
return v_res_1596_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__narrow(lean_object* v_w__lo_1597_, lean_object* v_w__hi_1598_, lean_object* v_r_1599_){
_start:
{
lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; 
lean_inc_ref(v_r_1599_);
v___x_1600_ = lp_parametric_PLDIProofs_stage2__project(v_w__lo_1597_, v_w__hi_1598_, v_r_1599_);
v___x_1601_ = ((lean_object*)(lp_parametric_PLDIProofs_stage2__project___closed__0));
v___x_1602_ = lp_parametric___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00PLDIProofs_stage2__narrow_spec__1(v_w__lo_1597_, v_w__hi_1598_, v_r_1599_, v___x_1600_, v___x_1601_);
return v___x_1602_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_stage2__narrow___boxed(lean_object* v_w__lo_1603_, lean_object* v_w__hi_1604_, lean_object* v_r_1605_){
_start:
{
lean_object* v_res_1606_; 
v_res_1606_ = lp_parametric_PLDIProofs_stage2__narrow(v_w__lo_1603_, v_w__hi_1604_, v_r_1605_);
lean_dec(v_w__hi_1604_);
lean_dec(v_w__lo_1603_);
return v_res_1606_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0(lean_object* v_w__lo_1607_, lean_object* v_w__hi_1608_, lean_object* v_B_1609_, lean_object* v_a_1610_, lean_object* v_a_1611_){
_start:
{
lean_object* v___x_1612_; 
v___x_1612_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___redArg(v_B_1609_, v_a_1610_, v_a_1611_);
return v___x_1612_;
}
}
LEAN_EXPORT lean_object* lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0___boxed(lean_object* v_w__lo_1613_, lean_object* v_w__hi_1614_, lean_object* v_B_1615_, lean_object* v_a_1616_, lean_object* v_a_1617_){
_start:
{
lean_object* v_res_1618_; 
v_res_1618_ = lp_parametric_List_filterMapTR_go___at___00PLDIProofs_stage2__narrow_spec__0(v_w__lo_1613_, v_w__hi_1614_, v_B_1615_, v_a_1616_, v_a_1617_);
lean_dec(v_w__hi_1614_);
lean_dec(v_w__lo_1613_);
return v_res_1618_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_tnumIntersectsInterval(lean_object* v_w_1619_, lean_object* v_t_1620_, lean_object* v_I_1621_){
_start:
{
lean_object* v_min_1622_; lean_object* v_max_1623_; lean_object* v_v_1624_; lean_object* v_m_1625_; lean_object* v___x_1626_; lean_object* v___x_1627_; uint8_t v___x_1628_; 
v_min_1622_ = lean_ctor_get(v_I_1621_, 0);
v_max_1623_ = lean_ctor_get(v_I_1621_, 1);
v_v_1624_ = lean_ctor_get(v_t_1620_, 0);
v_m_1625_ = lean_ctor_get(v_t_1620_, 1);
v___x_1626_ = l_BitVec_not(v_w_1619_, v_m_1625_);
v___x_1627_ = lean_nat_land(v_min_1622_, v___x_1626_);
lean_dec(v___x_1626_);
v___x_1628_ = lean_nat_dec_eq(v___x_1627_, v_v_1624_);
lean_dec(v___x_1627_);
if (v___x_1628_ == 0)
{
lean_object* v___x_1629_; uint8_t v___x_1630_; 
v___x_1629_ = lean_nat_lor(v_v_1624_, v_m_1625_);
v___x_1630_ = lean_nat_dec_lt(v_min_1622_, v___x_1629_);
lean_dec(v___x_1629_);
if (v___x_1630_ == 0)
{
return v___x_1630_;
}
else
{
lean_object* v___x_1631_; uint8_t v___x_1632_; 
v___x_1631_ = lp_parametric_PLDIProofs_tnum__step(v_w_1619_, v_t_1620_, v_min_1622_);
v___x_1632_ = lean_nat_dec_le(v___x_1631_, v_max_1623_);
lean_dec(v___x_1631_);
return v___x_1632_;
}
}
else
{
return v___x_1628_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_tnumIntersectsInterval___boxed(lean_object* v_w_1633_, lean_object* v_t_1634_, lean_object* v_I_1635_){
_start:
{
uint8_t v_res_1636_; lean_object* v_r_1637_; 
v_res_1636_ = lp_parametric_PLDIProofs_tnumIntersectsInterval(v_w_1633_, v_t_1634_, v_I_1635_);
lean_dec_ref(v_I_1635_);
lean_dec_ref(v_t_1634_);
lean_dec(v_w_1633_);
v_r_1637_ = lean_box(v_res_1636_);
return v_r_1637_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_checkBoxAgainstTnum(lean_object* v_w__lo_1638_, lean_object* v_w__hi_1639_, lean_object* v_t_1640_, lean_object* v_B_1641_){
_start:
{
lean_object* v_kRange_1642_; lean_object* v_subRange_1643_; lean_object* v___x_1644_; uint8_t v___x_1645_; 
v_kRange_1642_ = lean_ctor_get(v_B_1641_, 0);
v_subRange_1643_ = lean_ctor_get(v_B_1641_, 1);
lean_inc_ref(v_t_1640_);
v___x_1644_ = lp_parametric_PLDIProofs_tnumHi(v_w__lo_1638_, v_w__hi_1639_, v_t_1640_);
v___x_1645_ = lp_parametric_PLDIProofs_tnumIntersectsInterval(v_w__hi_1639_, v___x_1644_, v_kRange_1642_);
lean_dec_ref(v___x_1644_);
if (v___x_1645_ == 0)
{
lean_dec_ref(v_t_1640_);
return v___x_1645_;
}
else
{
lean_object* v___x_1646_; uint8_t v___x_1647_; 
v___x_1646_ = lp_parametric_PLDIProofs_tnumLo___redArg(v_w__lo_1638_, v_t_1640_);
v___x_1647_ = lp_parametric_PLDIProofs_tnumIntersectsInterval(v_w__lo_1638_, v___x_1646_, v_subRange_1643_);
lean_dec_ref(v___x_1646_);
return v___x_1647_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_checkBoxAgainstTnum___boxed(lean_object* v_w__lo_1648_, lean_object* v_w__hi_1649_, lean_object* v_t_1650_, lean_object* v_B_1651_){
_start:
{
uint8_t v_res_1652_; lean_object* v_r_1653_; 
v_res_1652_ = lp_parametric_PLDIProofs_checkBoxAgainstTnum(v_w__lo_1648_, v_w__hi_1649_, v_t_1650_, v_B_1651_);
lean_dec_ref(v_B_1651_);
lean_dec(v_w__hi_1649_);
lean_dec(v_w__lo_1648_);
v_r_1653_ = lean_box(v_res_1652_);
return v_r_1653_;
}
}
LEAN_EXPORT uint8_t lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0(lean_object* v_w__lo_1654_, lean_object* v_w__hi_1655_, lean_object* v___x_1656_, lean_object* v_x_1657_){
_start:
{
if (lean_obj_tag(v_x_1657_) == 0)
{
uint8_t v___x_1658_; 
lean_dec_ref(v___x_1656_);
v___x_1658_ = 0;
return v___x_1658_;
}
else
{
lean_object* v_head_1659_; lean_object* v_tail_1660_; uint8_t v___x_1661_; 
v_head_1659_ = lean_ctor_get(v_x_1657_, 0);
v_tail_1660_ = lean_ctor_get(v_x_1657_, 1);
lean_inc_ref(v___x_1656_);
v___x_1661_ = lp_parametric_PLDIProofs_checkBoxAgainstTnum(v_w__lo_1654_, v_w__hi_1655_, v___x_1656_, v_head_1659_);
if (v___x_1661_ == 0)
{
v_x_1657_ = v_tail_1660_;
goto _start;
}
else
{
lean_dec_ref(v___x_1656_);
return v___x_1661_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0___boxed(lean_object* v_w__lo_1663_, lean_object* v_w__hi_1664_, lean_object* v___x_1665_, lean_object* v_x_1666_){
_start:
{
uint8_t v_res_1667_; lean_object* v_r_1668_; 
v_res_1667_ = lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0(v_w__lo_1663_, v_w__hi_1664_, v___x_1665_, v_x_1666_);
lean_dec(v_x_1666_);
lean_dec(v_w__hi_1664_);
lean_dec(v_w__lo_1663_);
v_r_1668_ = lean_box(v_res_1667_);
return v_r_1668_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_reg__bounds__intersect(lean_object* v_w__lo_1669_, lean_object* v_w__hi_1670_, lean_object* v_r_1671_){
_start:
{
uint8_t v___x_1672_; 
lean_inc_ref(v_r_1671_);
v___x_1672_ = lp_parametric_PLDIProofs_instDecidableWF(v_w__lo_1669_, v_w__hi_1670_, v_r_1671_);
if (v___x_1672_ == 0)
{
lean_dec_ref(v_r_1671_);
return v___x_1672_;
}
else
{
lean_object* v_tnum_1673_; lean_object* v___x_1674_; uint8_t v___x_1675_; 
v_tnum_1673_ = lean_ctor_get(v_r_1671_, 4);
lean_inc_ref(v_tnum_1673_);
v___x_1674_ = lp_parametric_PLDIProofs_stage2__narrow(v_w__lo_1669_, v_w__hi_1670_, v_r_1671_);
v___x_1675_ = lp_parametric_List_any___at___00PLDIProofs_reg__bounds__intersect_spec__0(v_w__lo_1669_, v_w__hi_1670_, v_tnum_1673_, v___x_1674_);
lean_dec(v___x_1674_);
return v___x_1675_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_reg__bounds__intersect___boxed(lean_object* v_w__lo_1676_, lean_object* v_w__hi_1677_, lean_object* v_r_1678_){
_start:
{
uint8_t v_res_1679_; lean_object* v_r_1680_; 
v_res_1679_ = lp_parametric_PLDIProofs_reg__bounds__intersect(v_w__lo_1676_, v_w__hi_1677_, v_r_1678_);
lean_dec(v_w__hi_1677_);
lean_dec(v_w__lo_1676_);
v_r_1680_ = lean_box(v_res_1679_);
return v_r_1680_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__0(void){
_start:
{
lean_object* v___x_1681_; lean_object* v___x_1682_; lean_object* v___x_1683_; 
v___x_1681_ = lean_cstr_to_nat("4294967301");
v___x_1682_ = lean_unsigned_to_nat(64u);
v___x_1683_ = l_BitVec_ofNat(v___x_1682_, v___x_1681_);
return v___x_1683_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__1(void){
_start:
{
lean_object* v___x_1684_; lean_object* v___x_1685_; lean_object* v___x_1686_; 
v___x_1684_ = lean_cstr_to_nat("8589934595");
v___x_1685_ = lean_unsigned_to_nat(64u);
v___x_1686_ = l_BitVec_ofNat(v___x_1685_, v___x_1684_);
return v___x_1686_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__2(void){
_start:
{
lean_object* v___x_1687_; lean_object* v___x_1688_; lean_object* v___x_1689_; 
v___x_1687_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__1, &lp_parametric_PLDIProofs_fig6__example1__state___closed__1_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__1);
v___x_1688_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__0, &lp_parametric_PLDIProofs_fig6__example1__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__0);
v___x_1689_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1689_, 0, v___x_1688_);
lean_ctor_set(v___x_1689_, 1, v___x_1687_);
return v___x_1689_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__3(void){
_start:
{
lean_object* v___x_1690_; lean_object* v___x_1691_; lean_object* v___x_1692_; 
v___x_1690_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__1, &lp_parametric_PLDIProofs_fig6__example1__state___closed__1_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__1);
v___x_1691_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__0, &lp_parametric_PLDIProofs_fig6__example1__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__0);
v___x_1692_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1692_, 0, v___x_1691_);
lean_ctor_set(v___x_1692_, 1, v___x_1690_);
return v___x_1692_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__4(void){
_start:
{
lean_object* v___x_1693_; lean_object* v___x_1694_; lean_object* v___x_1695_; 
v___x_1693_ = lean_unsigned_to_nat(2u);
v___x_1694_ = lean_unsigned_to_nat(32u);
v___x_1695_ = l_BitVec_ofNat(v___x_1694_, v___x_1693_);
return v___x_1695_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__5(void){
_start:
{
lean_object* v___x_1696_; lean_object* v___x_1697_; lean_object* v___x_1698_; 
v___x_1696_ = lean_unsigned_to_nat(3u);
v___x_1697_ = lean_unsigned_to_nat(32u);
v___x_1698_ = l_BitVec_ofNat(v___x_1697_, v___x_1696_);
return v___x_1698_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__6(void){
_start:
{
lean_object* v___x_1699_; lean_object* v___x_1700_; lean_object* v___x_1701_; 
v___x_1699_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__5, &lp_parametric_PLDIProofs_fig6__example1__state___closed__5_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__5);
v___x_1700_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__4, &lp_parametric_PLDIProofs_fig6__example1__state___closed__4_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__4);
v___x_1701_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1701_, 0, v___x_1700_);
lean_ctor_set(v___x_1701_, 1, v___x_1699_);
return v___x_1701_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__7(void){
_start:
{
lean_object* v___x_1702_; lean_object* v___x_1703_; lean_object* v___x_1704_; 
v___x_1702_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__5, &lp_parametric_PLDIProofs_fig6__example1__state___closed__5_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__5);
v___x_1703_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__4, &lp_parametric_PLDIProofs_fig6__example1__state___closed__4_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__4);
v___x_1704_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1704_, 0, v___x_1703_);
lean_ctor_set(v___x_1704_, 1, v___x_1702_);
return v___x_1704_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__8(void){
_start:
{
lean_object* v___x_1705_; lean_object* v___x_1706_; lean_object* v___x_1707_; 
v___x_1705_ = lean_cstr_to_nat("8589934596");
v___x_1706_ = lean_unsigned_to_nat(64u);
v___x_1707_ = l_BitVec_ofNat(v___x_1706_, v___x_1705_);
return v___x_1707_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__9(void){
_start:
{
lean_object* v___x_1708_; lean_object* v___x_1709_; lean_object* v___x_1710_; 
v___x_1708_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__8, &lp_parametric_PLDIProofs_fig6__example1__state___closed__8_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__8);
v___x_1709_ = lean_obj_once(&lp_parametric_PLDIProofs_motivating__R0___closed__0, &lp_parametric_PLDIProofs_motivating__R0___closed__0_once, _init_lp_parametric_PLDIProofs_motivating__R0___closed__0);
v___x_1710_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1710_, 0, v___x_1709_);
lean_ctor_set(v___x_1710_, 1, v___x_1708_);
return v___x_1710_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__10(void){
_start:
{
lean_object* v___x_1711_; lean_object* v___x_1712_; lean_object* v___x_1713_; lean_object* v___x_1714_; lean_object* v___x_1715_; lean_object* v___x_1716_; 
v___x_1711_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__9, &lp_parametric_PLDIProofs_fig6__example1__state___closed__9_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__9);
v___x_1712_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__7, &lp_parametric_PLDIProofs_fig6__example1__state___closed__7_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__7);
v___x_1713_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__6, &lp_parametric_PLDIProofs_fig6__example1__state___closed__6_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__6);
v___x_1714_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__3, &lp_parametric_PLDIProofs_fig6__example1__state___closed__3_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__3);
v___x_1715_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__2, &lp_parametric_PLDIProofs_fig6__example1__state___closed__2_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__2);
v___x_1716_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_1716_, 0, v___x_1715_);
lean_ctor_set(v___x_1716_, 1, v___x_1714_);
lean_ctor_set(v___x_1716_, 2, v___x_1713_);
lean_ctor_set(v___x_1716_, 3, v___x_1712_);
lean_ctor_set(v___x_1716_, 4, v___x_1711_);
return v___x_1716_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example1__state(void){
_start:
{
lean_object* v___x_1717_; 
v___x_1717_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__10, &lp_parametric_PLDIProofs_fig6__example1__state___closed__10_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__10);
return v___x_1717_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__0(void){
_start:
{
lean_object* v___x_1718_; lean_object* v___x_1719_; lean_object* v___x_1720_; 
v___x_1718_ = lean_cstr_to_nat("8589934600");
v___x_1719_ = lean_unsigned_to_nat(64u);
v___x_1720_ = l_BitVec_ofNat(v___x_1719_, v___x_1718_);
return v___x_1720_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__1(void){
_start:
{
lean_object* v___x_1721_; lean_object* v___x_1722_; lean_object* v___x_1723_; 
v___x_1721_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__0, &lp_parametric_PLDIProofs_fig6__example2__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__0);
v___x_1722_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__0, &lp_parametric_PLDIProofs_fig6__example1__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__0);
v___x_1723_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1723_, 0, v___x_1722_);
lean_ctor_set(v___x_1723_, 1, v___x_1721_);
return v___x_1723_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__2(void){
_start:
{
lean_object* v___x_1724_; lean_object* v___x_1725_; lean_object* v___x_1726_; 
v___x_1724_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__0, &lp_parametric_PLDIProofs_fig6__example2__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__0);
v___x_1725_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__0, &lp_parametric_PLDIProofs_fig6__example1__state___closed__0_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__0);
v___x_1726_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1726_, 0, v___x_1725_);
lean_ctor_set(v___x_1726_, 1, v___x_1724_);
return v___x_1726_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__3(void){
_start:
{
lean_object* v___x_1727_; lean_object* v___x_1728_; lean_object* v___x_1729_; 
v___x_1727_ = lean_unsigned_to_nat(5u);
v___x_1728_ = lean_unsigned_to_nat(32u);
v___x_1729_ = l_BitVec_ofNat(v___x_1728_, v___x_1727_);
return v___x_1729_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__4(void){
_start:
{
lean_object* v___x_1730_; lean_object* v___x_1731_; lean_object* v___x_1732_; 
v___x_1730_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__3, &lp_parametric_PLDIProofs_fig6__example2__state___closed__3_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__3);
v___x_1731_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__4, &lp_parametric_PLDIProofs_fig6__example1__state___closed__4_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__4);
v___x_1732_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1732_, 0, v___x_1731_);
lean_ctor_set(v___x_1732_, 1, v___x_1730_);
return v___x_1732_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__5(void){
_start:
{
lean_object* v___x_1733_; lean_object* v___x_1734_; lean_object* v___x_1735_; 
v___x_1733_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__3, &lp_parametric_PLDIProofs_fig6__example2__state___closed__3_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__3);
v___x_1734_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__4, &lp_parametric_PLDIProofs_fig6__example1__state___closed__4_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__4);
v___x_1735_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1735_, 0, v___x_1734_);
lean_ctor_set(v___x_1735_, 1, v___x_1733_);
return v___x_1735_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__6(void){
_start:
{
lean_object* v___x_1736_; lean_object* v___x_1737_; lean_object* v___x_1738_; lean_object* v___x_1739_; lean_object* v___x_1740_; lean_object* v___x_1741_; 
v___x_1736_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example1__state___closed__9, &lp_parametric_PLDIProofs_fig6__example1__state___closed__9_once, _init_lp_parametric_PLDIProofs_fig6__example1__state___closed__9);
v___x_1737_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__5, &lp_parametric_PLDIProofs_fig6__example2__state___closed__5_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__5);
v___x_1738_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__4, &lp_parametric_PLDIProofs_fig6__example2__state___closed__4_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__4);
v___x_1739_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__2, &lp_parametric_PLDIProofs_fig6__example2__state___closed__2_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__2);
v___x_1740_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__1, &lp_parametric_PLDIProofs_fig6__example2__state___closed__1_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__1);
v___x_1741_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_1741_, 0, v___x_1740_);
lean_ctor_set(v___x_1741_, 1, v___x_1739_);
lean_ctor_set(v___x_1741_, 2, v___x_1738_);
lean_ctor_set(v___x_1741_, 3, v___x_1737_);
lean_ctor_set(v___x_1741_, 4, v___x_1736_);
return v___x_1741_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_fig6__example2__state(void){
_start:
{
lean_object* v___x_1742_; 
v___x_1742_ = lean_obj_once(&lp_parametric_PLDIProofs_fig6__example2__state___closed__6, &lp_parametric_PLDIProofs_fig6__example2__state___closed__6_once, _init_lp_parametric_PLDIProofs_fig6__example2__state___closed__6);
return v___x_1742_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorIdx(uint8_t v_x_1743_){
_start:
{
switch(v_x_1743_)
{
case 0:
{
lean_object* v___x_1744_; 
v___x_1744_ = lean_unsigned_to_nat(0u);
return v___x_1744_;
}
case 1:
{
lean_object* v___x_1745_; 
v___x_1745_ = lean_unsigned_to_nat(1u);
return v___x_1745_;
}
case 2:
{
lean_object* v___x_1746_; 
v___x_1746_ = lean_unsigned_to_nat(2u);
return v___x_1746_;
}
default: 
{
lean_object* v___x_1747_; 
v___x_1747_ = lean_unsigned_to_nat(3u);
return v___x_1747_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorIdx___boxed(lean_object* v_x_1748_){
_start:
{
uint8_t v_x_boxed_1749_; lean_object* v_res_1750_; 
v_x_boxed_1749_ = lean_unbox(v_x_1748_);
v_res_1750_ = lp_parametric_PLDIProofs_BranchResolution_ctorIdx(v_x_boxed_1749_);
return v_res_1750_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___redArg(lean_object* v_k_1751_){
_start:
{
lean_inc(v_k_1751_);
return v_k_1751_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___redArg___boxed(lean_object* v_k_1752_){
_start:
{
lean_object* v_res_1753_; 
v_res_1753_ = lp_parametric_PLDIProofs_BranchResolution_ctorElim___redArg(v_k_1752_);
lean_dec(v_k_1752_);
return v_res_1753_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim(lean_object* v_motive_1754_, lean_object* v_ctorIdx_1755_, uint8_t v_t_1756_, lean_object* v_h_1757_, lean_object* v_k_1758_){
_start:
{
lean_inc(v_k_1758_);
return v_k_1758_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ctorElim___boxed(lean_object* v_motive_1759_, lean_object* v_ctorIdx_1760_, lean_object* v_t_1761_, lean_object* v_h_1762_, lean_object* v_k_1763_){
_start:
{
uint8_t v_t_boxed_1764_; lean_object* v_res_1765_; 
v_t_boxed_1764_ = lean_unbox(v_t_1761_);
v_res_1765_ = lp_parametric_PLDIProofs_BranchResolution_ctorElim(v_motive_1759_, v_ctorIdx_1760_, v_t_boxed_1764_, v_h_1762_, v_k_1763_);
lean_dec(v_k_1763_);
lean_dec(v_ctorIdx_1760_);
return v_res_1765_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___redArg(lean_object* v_takenOnly_1766_){
_start:
{
lean_inc(v_takenOnly_1766_);
return v_takenOnly_1766_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___redArg___boxed(lean_object* v_takenOnly_1767_){
_start:
{
lean_object* v_res_1768_; 
v_res_1768_ = lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___redArg(v_takenOnly_1767_);
lean_dec(v_takenOnly_1767_);
return v_res_1768_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim(lean_object* v_motive_1769_, uint8_t v_t_1770_, lean_object* v_h_1771_, lean_object* v_takenOnly_1772_){
_start:
{
lean_inc(v_takenOnly_1772_);
return v_takenOnly_1772_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim___boxed(lean_object* v_motive_1773_, lean_object* v_t_1774_, lean_object* v_h_1775_, lean_object* v_takenOnly_1776_){
_start:
{
uint8_t v_t_boxed_1777_; lean_object* v_res_1778_; 
v_t_boxed_1777_ = lean_unbox(v_t_1774_);
v_res_1778_ = lp_parametric_PLDIProofs_BranchResolution_takenOnly_elim(v_motive_1773_, v_t_boxed_1777_, v_h_1775_, v_takenOnly_1776_);
lean_dec(v_takenOnly_1776_);
return v_res_1778_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___redArg(lean_object* v_fallthroughOnly_1779_){
_start:
{
lean_inc(v_fallthroughOnly_1779_);
return v_fallthroughOnly_1779_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___redArg___boxed(lean_object* v_fallthroughOnly_1780_){
_start:
{
lean_object* v_res_1781_; 
v_res_1781_ = lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___redArg(v_fallthroughOnly_1780_);
lean_dec(v_fallthroughOnly_1780_);
return v_res_1781_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim(lean_object* v_motive_1782_, uint8_t v_t_1783_, lean_object* v_h_1784_, lean_object* v_fallthroughOnly_1785_){
_start:
{
lean_inc(v_fallthroughOnly_1785_);
return v_fallthroughOnly_1785_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim___boxed(lean_object* v_motive_1786_, lean_object* v_t_1787_, lean_object* v_h_1788_, lean_object* v_fallthroughOnly_1789_){
_start:
{
uint8_t v_t_boxed_1790_; lean_object* v_res_1791_; 
v_t_boxed_1790_ = lean_unbox(v_t_1787_);
v_res_1791_ = lp_parametric_PLDIProofs_BranchResolution_fallthroughOnly_elim(v_motive_1786_, v_t_boxed_1790_, v_h_1788_, v_fallthroughOnly_1789_);
lean_dec(v_fallthroughOnly_1789_);
return v_res_1791_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___redArg(lean_object* v_bothFeasible_1792_){
_start:
{
lean_inc(v_bothFeasible_1792_);
return v_bothFeasible_1792_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___redArg___boxed(lean_object* v_bothFeasible_1793_){
_start:
{
lean_object* v_res_1794_; 
v_res_1794_ = lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___redArg(v_bothFeasible_1793_);
lean_dec(v_bothFeasible_1793_);
return v_res_1794_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim(lean_object* v_motive_1795_, uint8_t v_t_1796_, lean_object* v_h_1797_, lean_object* v_bothFeasible_1798_){
_start:
{
lean_inc(v_bothFeasible_1798_);
return v_bothFeasible_1798_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim___boxed(lean_object* v_motive_1799_, lean_object* v_t_1800_, lean_object* v_h_1801_, lean_object* v_bothFeasible_1802_){
_start:
{
uint8_t v_t_boxed_1803_; lean_object* v_res_1804_; 
v_t_boxed_1803_ = lean_unbox(v_t_1800_);
v_res_1804_ = lp_parametric_PLDIProofs_BranchResolution_bothFeasible_elim(v_motive_1799_, v_t_boxed_1803_, v_h_1801_, v_bothFeasible_1802_);
lean_dec(v_bothFeasible_1802_);
return v_res_1804_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___redArg(lean_object* v_unreachableNode_1805_){
_start:
{
lean_inc(v_unreachableNode_1805_);
return v_unreachableNode_1805_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___redArg___boxed(lean_object* v_unreachableNode_1806_){
_start:
{
lean_object* v_res_1807_; 
v_res_1807_ = lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___redArg(v_unreachableNode_1806_);
lean_dec(v_unreachableNode_1806_);
return v_res_1807_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim(lean_object* v_motive_1808_, uint8_t v_t_1809_, lean_object* v_h_1810_, lean_object* v_unreachableNode_1811_){
_start:
{
lean_inc(v_unreachableNode_1811_);
return v_unreachableNode_1811_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim___boxed(lean_object* v_motive_1812_, lean_object* v_t_1813_, lean_object* v_h_1814_, lean_object* v_unreachableNode_1815_){
_start:
{
uint8_t v_t_boxed_1816_; lean_object* v_res_1817_; 
v_t_boxed_1816_ = lean_unbox(v_t_1813_);
v_res_1817_ = lp_parametric_PLDIProofs_BranchResolution_unreachableNode_elim(v_motive_1812_, v_t_boxed_1816_, v_h_1814_, v_unreachableNode_1815_);
lean_dec(v_unreachableNode_1815_);
return v_res_1817_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_BranchResolution_ofNat(lean_object* v_n_1818_){
_start:
{
lean_object* v___x_1819_; uint8_t v___x_1820_; 
v___x_1819_ = lean_unsigned_to_nat(1u);
v___x_1820_ = lean_nat_dec_le(v_n_1818_, v___x_1819_);
if (v___x_1820_ == 0)
{
lean_object* v___x_1821_; uint8_t v___x_1822_; 
v___x_1821_ = lean_unsigned_to_nat(2u);
v___x_1822_ = lean_nat_dec_le(v_n_1818_, v___x_1821_);
if (v___x_1822_ == 0)
{
uint8_t v___x_1823_; 
v___x_1823_ = 3;
return v___x_1823_;
}
else
{
uint8_t v___x_1824_; 
v___x_1824_ = 2;
return v___x_1824_;
}
}
else
{
lean_object* v___x_1825_; uint8_t v___x_1826_; 
v___x_1825_ = lean_unsigned_to_nat(0u);
v___x_1826_ = lean_nat_dec_le(v_n_1818_, v___x_1825_);
if (v___x_1826_ == 0)
{
uint8_t v___x_1827_; 
v___x_1827_ = 1;
return v___x_1827_;
}
else
{
uint8_t v___x_1828_; 
v___x_1828_ = 0;
return v___x_1828_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_BranchResolution_ofNat___boxed(lean_object* v_n_1829_){
_start:
{
uint8_t v_res_1830_; lean_object* v_r_1831_; 
v_res_1830_ = lp_parametric_PLDIProofs_BranchResolution_ofNat(v_n_1829_);
lean_dec(v_n_1829_);
v_r_1831_ = lean_box(v_res_1830_);
return v_r_1831_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_instDecidableEqBranchResolution(uint8_t v_x_1832_, uint8_t v_y_1833_){
_start:
{
lean_object* v___x_1834_; lean_object* v___x_1835_; uint8_t v___x_1836_; 
v___x_1834_ = lp_parametric_PLDIProofs_BranchResolution_ctorIdx(v_x_1832_);
v___x_1835_ = lp_parametric_PLDIProofs_BranchResolution_ctorIdx(v_y_1833_);
v___x_1836_ = lean_nat_dec_eq(v___x_1834_, v___x_1835_);
lean_dec(v___x_1835_);
lean_dec(v___x_1834_);
return v___x_1836_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instDecidableEqBranchResolution___boxed(lean_object* v_x_1837_, lean_object* v_y_1838_){
_start:
{
uint8_t v_x_13__boxed_1839_; uint8_t v_y_14__boxed_1840_; uint8_t v_res_1841_; lean_object* v_r_1842_; 
v_x_13__boxed_1839_ = lean_unbox(v_x_1837_);
v_y_14__boxed_1840_ = lean_unbox(v_y_1838_);
v_res_1841_ = lp_parametric_PLDIProofs_instDecidableEqBranchResolution(v_x_13__boxed_1839_, v_y_14__boxed_1840_);
v_r_1842_ = lean_box(v_res_1841_);
return v_r_1842_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8(void){
_start:
{
lean_object* v___x_1855_; lean_object* v___x_1856_; 
v___x_1855_ = lean_unsigned_to_nat(2u);
v___x_1856_ = lean_nat_to_int(v___x_1855_);
return v___x_1856_;
}
}
static lean_object* _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9(void){
_start:
{
lean_object* v___x_1857_; lean_object* v___x_1858_; 
v___x_1857_ = lean_unsigned_to_nat(1u);
v___x_1858_ = lean_nat_to_int(v___x_1857_);
return v___x_1858_;
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr(uint8_t v_x_1859_, lean_object* v_prec_1860_){
_start:
{
lean_object* v___y_1862_; lean_object* v___y_1869_; lean_object* v___y_1876_; lean_object* v___y_1883_; 
switch(v_x_1859_)
{
case 0:
{
lean_object* v___x_1889_; uint8_t v___x_1890_; 
v___x_1889_ = lean_unsigned_to_nat(1024u);
v___x_1890_ = lean_nat_dec_le(v___x_1889_, v_prec_1860_);
if (v___x_1890_ == 0)
{
lean_object* v___x_1891_; 
v___x_1891_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8);
v___y_1862_ = v___x_1891_;
goto v___jp_1861_;
}
else
{
lean_object* v___x_1892_; 
v___x_1892_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9);
v___y_1862_ = v___x_1892_;
goto v___jp_1861_;
}
}
case 1:
{
lean_object* v___x_1893_; uint8_t v___x_1894_; 
v___x_1893_ = lean_unsigned_to_nat(1024u);
v___x_1894_ = lean_nat_dec_le(v___x_1893_, v_prec_1860_);
if (v___x_1894_ == 0)
{
lean_object* v___x_1895_; 
v___x_1895_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8);
v___y_1869_ = v___x_1895_;
goto v___jp_1868_;
}
else
{
lean_object* v___x_1896_; 
v___x_1896_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9);
v___y_1869_ = v___x_1896_;
goto v___jp_1868_;
}
}
case 2:
{
lean_object* v___x_1897_; uint8_t v___x_1898_; 
v___x_1897_ = lean_unsigned_to_nat(1024u);
v___x_1898_ = lean_nat_dec_le(v___x_1897_, v_prec_1860_);
if (v___x_1898_ == 0)
{
lean_object* v___x_1899_; 
v___x_1899_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8);
v___y_1876_ = v___x_1899_;
goto v___jp_1875_;
}
else
{
lean_object* v___x_1900_; 
v___x_1900_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9);
v___y_1876_ = v___x_1900_;
goto v___jp_1875_;
}
}
default: 
{
lean_object* v___x_1901_; uint8_t v___x_1902_; 
v___x_1901_ = lean_unsigned_to_nat(1024u);
v___x_1902_ = lean_nat_dec_le(v___x_1901_, v_prec_1860_);
if (v___x_1902_ == 0)
{
lean_object* v___x_1903_; 
v___x_1903_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__8);
v___y_1883_ = v___x_1903_;
goto v___jp_1882_;
}
else
{
lean_object* v___x_1904_; 
v___x_1904_ = lean_obj_once(&lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9, &lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9_once, _init_lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__9);
v___y_1883_ = v___x_1904_;
goto v___jp_1882_;
}
}
}
v___jp_1861_:
{
lean_object* v___x_1863_; lean_object* v___x_1864_; uint8_t v___x_1865_; lean_object* v___x_1866_; lean_object* v___x_1867_; 
v___x_1863_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__1));
lean_inc(v___y_1862_);
v___x_1864_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1864_, 0, v___y_1862_);
lean_ctor_set(v___x_1864_, 1, v___x_1863_);
v___x_1865_ = 0;
v___x_1866_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1866_, 0, v___x_1864_);
lean_ctor_set_uint8(v___x_1866_, sizeof(void*)*1, v___x_1865_);
v___x_1867_ = l_Repr_addAppParen(v___x_1866_, v_prec_1860_);
return v___x_1867_;
}
v___jp_1868_:
{
lean_object* v___x_1870_; lean_object* v___x_1871_; uint8_t v___x_1872_; lean_object* v___x_1873_; lean_object* v___x_1874_; 
v___x_1870_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__3));
lean_inc(v___y_1869_);
v___x_1871_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1871_, 0, v___y_1869_);
lean_ctor_set(v___x_1871_, 1, v___x_1870_);
v___x_1872_ = 0;
v___x_1873_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1873_, 0, v___x_1871_);
lean_ctor_set_uint8(v___x_1873_, sizeof(void*)*1, v___x_1872_);
v___x_1874_ = l_Repr_addAppParen(v___x_1873_, v_prec_1860_);
return v___x_1874_;
}
v___jp_1875_:
{
lean_object* v___x_1877_; lean_object* v___x_1878_; uint8_t v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; 
v___x_1877_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__5));
lean_inc(v___y_1876_);
v___x_1878_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1878_, 0, v___y_1876_);
lean_ctor_set(v___x_1878_, 1, v___x_1877_);
v___x_1879_ = 0;
v___x_1880_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1880_, 0, v___x_1878_);
lean_ctor_set_uint8(v___x_1880_, sizeof(void*)*1, v___x_1879_);
v___x_1881_ = l_Repr_addAppParen(v___x_1880_, v_prec_1860_);
return v___x_1881_;
}
v___jp_1882_:
{
lean_object* v___x_1884_; lean_object* v___x_1885_; uint8_t v___x_1886_; lean_object* v___x_1887_; lean_object* v___x_1888_; 
v___x_1884_ = ((lean_object*)(lp_parametric_PLDIProofs_instReprBranchResolution_repr___closed__7));
lean_inc(v___y_1883_);
v___x_1885_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_1885_, 0, v___y_1883_);
lean_ctor_set(v___x_1885_, 1, v___x_1884_);
v___x_1886_ = 0;
v___x_1887_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_1887_, 0, v___x_1885_);
lean_ctor_set_uint8(v___x_1887_, sizeof(void*)*1, v___x_1886_);
v___x_1888_ = l_Repr_addAppParen(v___x_1887_, v_prec_1860_);
return v___x_1888_;
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_instReprBranchResolution_repr___boxed(lean_object* v_x_1905_, lean_object* v_prec_1906_){
_start:
{
uint8_t v_x_233__boxed_1907_; lean_object* v_res_1908_; 
v_x_233__boxed_1907_ = lean_unbox(v_x_1905_);
v_res_1908_ = lp_parametric_PLDIProofs_instReprBranchResolution_repr(v_x_233__boxed_1907_, v_prec_1906_);
lean_dec(v_prec_1906_);
return v_res_1908_;
}
}
LEAN_EXPORT uint8_t lp_parametric_PLDIProofs_simulate__both__branches__taken(lean_object* v_w__lo_1911_, lean_object* v_w__hi_1912_, lean_object* v_refineTrue_1913_, lean_object* v_refineFalse_1914_, lean_object* v_r1_1915_, lean_object* v_r2_1916_){
_start:
{
uint8_t v___y_1918_; uint8_t v___y_1919_; lean_object* v___x_1924_; lean_object* v_fst_1925_; lean_object* v_snd_1926_; lean_object* v___x_1927_; lean_object* v_fst_1928_; lean_object* v_snd_1929_; uint8_t v___y_1931_; uint8_t v___x_1934_; 
lean_inc_ref(v_r2_1916_);
lean_inc_ref(v_r1_1915_);
v___x_1924_ = lean_apply_2(v_refineTrue_1913_, v_r1_1915_, v_r2_1916_);
v_fst_1925_ = lean_ctor_get(v___x_1924_, 0);
lean_inc(v_fst_1925_);
v_snd_1926_ = lean_ctor_get(v___x_1924_, 1);
lean_inc(v_snd_1926_);
lean_dec_ref(v___x_1924_);
v___x_1927_ = lean_apply_2(v_refineFalse_1914_, v_r1_1915_, v_r2_1916_);
v_fst_1928_ = lean_ctor_get(v___x_1927_, 0);
lean_inc(v_fst_1928_);
v_snd_1929_ = lean_ctor_get(v___x_1927_, 1);
lean_inc(v_snd_1929_);
lean_dec_ref(v___x_1927_);
v___x_1934_ = lp_parametric_PLDIProofs_reg__bounds__intersect(v_w__lo_1911_, v_w__hi_1912_, v_fst_1925_);
if (v___x_1934_ == 0)
{
lean_dec(v_snd_1926_);
v___y_1931_ = v___x_1934_;
goto v___jp_1930_;
}
else
{
uint8_t v___x_1935_; 
v___x_1935_ = lp_parametric_PLDIProofs_reg__bounds__intersect(v_w__lo_1911_, v_w__hi_1912_, v_snd_1926_);
v___y_1931_ = v___x_1935_;
goto v___jp_1930_;
}
v___jp_1917_:
{
if (v___y_1918_ == 0)
{
if (v___y_1919_ == 0)
{
uint8_t v___x_1920_; 
v___x_1920_ = 3;
return v___x_1920_;
}
else
{
uint8_t v___x_1921_; 
v___x_1921_ = 1;
return v___x_1921_;
}
}
else
{
if (v___y_1919_ == 0)
{
uint8_t v___x_1922_; 
v___x_1922_ = 0;
return v___x_1922_;
}
else
{
uint8_t v___x_1923_; 
v___x_1923_ = 2;
return v___x_1923_;
}
}
}
v___jp_1930_:
{
uint8_t v___x_1932_; 
v___x_1932_ = lp_parametric_PLDIProofs_reg__bounds__intersect(v_w__lo_1911_, v_w__hi_1912_, v_fst_1928_);
if (v___x_1932_ == 0)
{
lean_dec(v_snd_1929_);
v___y_1918_ = v___y_1931_;
v___y_1919_ = v___x_1932_;
goto v___jp_1917_;
}
else
{
uint8_t v___x_1933_; 
v___x_1933_ = lp_parametric_PLDIProofs_reg__bounds__intersect(v_w__lo_1911_, v_w__hi_1912_, v_snd_1929_);
v___y_1918_ = v___y_1931_;
v___y_1919_ = v___x_1933_;
goto v___jp_1917_;
}
}
}
}
LEAN_EXPORT lean_object* lp_parametric_PLDIProofs_simulate__both__branches__taken___boxed(lean_object* v_w__lo_1936_, lean_object* v_w__hi_1937_, lean_object* v_refineTrue_1938_, lean_object* v_refineFalse_1939_, lean_object* v_r1_1940_, lean_object* v_r2_1941_){
_start:
{
uint8_t v_res_1942_; lean_object* v_r_1943_; 
v_res_1942_ = lp_parametric_PLDIProofs_simulate__both__branches__taken(v_w__lo_1936_, v_w__hi_1937_, v_refineTrue_1938_, v_refineFalse_1939_, v_r1_1940_, v_r2_1941_);
lean_dec(v_w__hi_1937_);
lean_dec(v_w__lo_1936_);
v_r_1943_ = lean_box(v_res_1942_);
return v_r_1943_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_parametric_PLDIProofs(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_parametric_PLDIProofs_motivating__R0 = _init_lp_parametric_PLDIProofs_motivating__R0();
lean_mark_persistent(lp_parametric_PLDIProofs_motivating__R0);
lp_parametric_PLDIProofs_motivating__R1__EI = _init_lp_parametric_PLDIProofs_motivating__R1__EI();
lean_mark_persistent(lp_parametric_PLDIProofs_motivating__R1__EI);
lp_parametric_PLDIProofs_motivating__R2__IF = _init_lp_parametric_PLDIProofs_motivating__R2__IF();
lean_mark_persistent(lp_parametric_PLDIProofs_motivating__R2__IF);
lp_parametric_PLDIProofs_fig3__D1 = _init_lp_parametric_PLDIProofs_fig3__D1();
lean_mark_persistent(lp_parametric_PLDIProofs_fig3__D1);
lp_parametric_PLDIProofs_fig3__D2 = _init_lp_parametric_PLDIProofs_fig3__D2();
lean_mark_persistent(lp_parametric_PLDIProofs_fig3__D2);
lp_parametric_PLDIProofs_fig6__example1__state = _init_lp_parametric_PLDIProofs_fig6__example1__state();
lean_mark_persistent(lp_parametric_PLDIProofs_fig6__example1__state);
lp_parametric_PLDIProofs_fig6__example2__state = _init_lp_parametric_PLDIProofs_fig6__example2__state();
lean_mark_persistent(lp_parametric_PLDIProofs_fig6__example2__state);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
