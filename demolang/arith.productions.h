#ifndef ARITH_PRODUCTIONS_H_INCLUDED
#define ARITH_PRODUCTIONS_H_INCLUDED

#include "../tools/token.h"
#include "arith.production_tree.h"
#include "arith.parser.h"

enum arith_production {
  arith_production_assign_production_expr_to_program = 0,
  arith_production_custom_production_control_expr_to_program = 1,
  arith_production_custom_production_result_expr_to_program = 2,
  arith_production_custom_production_control_result_expr_to_program = 3,
  arith_production_custom_production_FromInteger = 4,
  arith_production_custom_production_FromControl = 5,
  arith_production_custom_production_BinOpPlus = 6,
  arith_production_custom_production_BinOpMinus = 7,
  arith_production_custom_production_BinOpTimes = 8,
  arith_production_custom_production_BinOpDivide = 9,
  arith_production_custom_production_BinOpRemainder = 10,
  arith_production_custom_production_BinOpAsh = 11,
  arith_production_custom_production_BinOpLsh = 12,
  arith_production_custom_production_BinOpRsh = 13,
  arith_production_custom_production_BinOpBitNot = 14,
  arith_production_custom_production_BinOpBitOr = 15,
  arith_production_custom_production_BinOpBitAnd = 16,
  arith_production_custom_production_BinOpBitXor = 17,
  arith_production_custom_production_BinOpCmp = 18,
  arith_production_custom_production_UnOpAbsolute = 19,
  arith_production_custom_production_UnOpNegate = 20,
  arith_production_custom_production_UnOpIncrement = 21,
  arith_production_custom_production_UnOpDecrement = 22,
};
enum { arith_production_count = 23 };
extern const char*arith_production_names[arith_production_count];

// AssignProduction expr_to_program -> arith_grouping_program
proto arith_assign_production_expr_to_program(struct arith_parse_state * ,proto /*expr*/ x1);

// CustomProduction control_expr_to_program -> arith_grouping_program
proto arith_custom_production_control_expr_to_program(struct arith_parse_state * ,proto /*control_block*/ x1 ,token /*SPACE*/ x2 ,proto /*expr*/ x3);

// CustomProduction result_expr_to_program -> arith_grouping_program
proto arith_custom_production_result_expr_to_program(struct arith_parse_state * ,proto /*integer*/ x1 ,token /*SPACE*/ x2 ,proto /*expr*/ x3);

// CustomProduction control_result_expr_to_program -> arith_grouping_program
proto arith_custom_production_control_result_expr_to_program(struct arith_parse_state * ,proto /*control_block*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*expr*/ x5);

// CustomProduction FromInteger -> arith_grouping_integer
proto arith_custom_production_FromInteger(struct arith_parse_state * ,token /*INTEGER*/ x1);

// CustomProduction FromControl -> arith_grouping_control_block
proto arith_custom_production_FromControl(struct arith_parse_state * ,token /*CONTROL*/ x1);

// CustomProduction BinOpPlus -> arith_grouping_expr
proto arith_custom_production_BinOpPlus(struct arith_parse_state * ,token /*PLUS*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpMinus -> arith_grouping_expr
proto arith_custom_production_BinOpMinus(struct arith_parse_state * ,token /*MINUS*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpTimes -> arith_grouping_expr
proto arith_custom_production_BinOpTimes(struct arith_parse_state * ,token /*TIMES*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpDivide -> arith_grouping_expr
proto arith_custom_production_BinOpDivide(struct arith_parse_state * ,token /*DIVIDE*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpRemainder -> arith_grouping_expr
proto arith_custom_production_BinOpRemainder(struct arith_parse_state * ,token /*REMAINDER*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpAsh -> arith_grouping_expr
proto arith_custom_production_BinOpAsh(struct arith_parse_state * ,token /*ASH*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpLsh -> arith_grouping_expr
proto arith_custom_production_BinOpLsh(struct arith_parse_state * ,token /*LSH*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpRsh -> arith_grouping_expr
proto arith_custom_production_BinOpRsh(struct arith_parse_state * ,token /*RSH*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpBitNot -> arith_grouping_expr
proto arith_custom_production_BinOpBitNot(struct arith_parse_state * ,token /*BITNOT*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*NEWLINE*/ x4);

// CustomProduction BinOpBitOr -> arith_grouping_expr
proto arith_custom_production_BinOpBitOr(struct arith_parse_state * ,token /*BITOR*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpBitAnd -> arith_grouping_expr
proto arith_custom_production_BinOpBitAnd(struct arith_parse_state * ,token /*BITAND*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpBitXor -> arith_grouping_expr
proto arith_custom_production_BinOpBitXor(struct arith_parse_state * ,token /*BITXOR*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction BinOpCmp -> arith_grouping_expr
proto arith_custom_production_BinOpCmp(struct arith_parse_state * ,token /*CMP*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*SPACE*/ x4 ,proto /*integer*/ x5 ,token /*NEWLINE*/ x6);

// CustomProduction UnOpAbsolute -> arith_grouping_expr
proto arith_custom_production_UnOpAbsolute(struct arith_parse_state * ,token /*ABSOLUTE*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*NEWLINE*/ x4);

// CustomProduction UnOpNegate -> arith_grouping_expr
proto arith_custom_production_UnOpNegate(struct arith_parse_state * ,token /*NEGATE*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*NEWLINE*/ x4);

// CustomProduction UnOpIncrement -> arith_grouping_expr
proto arith_custom_production_UnOpIncrement(struct arith_parse_state * ,token /*INCREMENT*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*NEWLINE*/ x4);

// CustomProduction UnOpDecrement -> arith_grouping_expr
proto arith_custom_production_UnOpDecrement(struct arith_parse_state * ,token /*DECREMENT*/ x1 ,token /*SPACE*/ x2 ,proto /*integer*/ x3 ,token /*NEWLINE*/ x4);


#endif // ARITH_PRODUCTIONS_H_INCLUDED
