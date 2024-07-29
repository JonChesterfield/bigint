#include "arith.productions.h"
const char*arith_production_names[arith_production_count] = {
  [arith_production_assign_production_expr_to_program] = "assign_production_expr_to_program",
  [arith_production_custom_production_control_expr_to_program] = "custom_production_control_expr_to_program",
  [arith_production_custom_production_result_expr_to_program] = "custom_production_result_expr_to_program",
  [arith_production_custom_production_control_result_expr_to_program] = "custom_production_control_result_expr_to_program",
  [arith_production_custom_production_FromInteger] = "custom_production_FromInteger",
  [arith_production_custom_production_FromControl] = "custom_production_FromControl",
  [arith_production_custom_production_BinOpPlus] = "custom_production_BinOpPlus",
  [arith_production_custom_production_BinOpMinus] = "custom_production_BinOpMinus",
  [arith_production_custom_production_BinOpTimes] = "custom_production_BinOpTimes",
  [arith_production_custom_production_BinOpDivide] = "custom_production_BinOpDivide",
  [arith_production_custom_production_BinOpRemainder] = "custom_production_BinOpRemainder",
  [arith_production_custom_production_BinOpBitOr] = "custom_production_BinOpBitOr",
  [arith_production_custom_production_BinOpBitAnd] = "custom_production_BinOpBitAnd",
  [arith_production_custom_production_BinOpBitXor] = "custom_production_BinOpBitXor",
  [arith_production_custom_production_BinOpCmp] = "custom_production_BinOpCmp",
  [arith_production_custom_production_UnOpAbsolute] = "custom_production_UnOpAbsolute",
  [arith_production_custom_production_UnOpNegate] = "custom_production_UnOpNegate",
  [arith_production_custom_production_UnOpIncrement] = "custom_production_UnOpIncrement",
  [arith_production_custom_production_UnOpDecrement] = "custom_production_UnOpDecrement",};
extern const char*arith_production_names[arith_production_count];


