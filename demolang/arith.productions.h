#ifndef ARITH_PRODUCTIONS_H_INCLUDED
#define ARITH_PRODUCTIONS_H_INCLUDED

#include "../tools/token.h"
#include "arith.production_tree.h"
#include "arith.parser.h"

enum arith_production {
  arith_production_assign_production_expression_to_program = 0,
  arith_production_custom_production_BinOpPlus = 1,
  arith_production_custom_production_BinOpMinus = 2,
  arith_production_custom_production_BinOpTimes = 3,
  arith_production_custom_production_BinOpDivide = 4,
  arith_production_custom_production_BinOpRemainder = 5,
  arith_production_custom_production_BinOpBitOr = 6,
  arith_production_custom_production_BinOpBitAnd = 7,
  arith_production_custom_production_BinOpBitXor = 8,
  arith_production_custom_production_UnOpAbsolute = 9,
  arith_production_custom_production_UnOpNegate = 10,
  arith_production_custom_production_UnOpIncrement = 11,
  arith_production_custom_production_UnOpDecrement = 12,
  arith_production_assign_production_Parenthesised = 13,
  arith_production_custom_production_FromInteger = 14,
};
enum { arith_production_count = 15 };
extern const char*arith_production_names[arith_production_count];

// AssignProduction expression_to_program -> arith_grouping_program
proto arith_assign_production_expression_to_program(struct arith_parse_state * ,proto /*expr*/ x1);

// CustomProduction BinOpPlus -> arith_grouping_expr
proto arith_custom_production_BinOpPlus(struct arith_parse_state * ,token /*PLUS*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpMinus -> arith_grouping_expr
proto arith_custom_production_BinOpMinus(struct arith_parse_state * ,token /*MINUS*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpTimes -> arith_grouping_expr
proto arith_custom_production_BinOpTimes(struct arith_parse_state * ,token /*TIMES*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpDivide -> arith_grouping_expr
proto arith_custom_production_BinOpDivide(struct arith_parse_state * ,token /*DIVIDE*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpRemainder -> arith_grouping_expr
proto arith_custom_production_BinOpRemainder(struct arith_parse_state * ,token /*REMAINDER*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpBitOr -> arith_grouping_expr
proto arith_custom_production_BinOpBitOr(struct arith_parse_state * ,token /*BITOR*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpBitAnd -> arith_grouping_expr
proto arith_custom_production_BinOpBitAnd(struct arith_parse_state * ,token /*BITAND*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction BinOpBitXor -> arith_grouping_expr
proto arith_custom_production_BinOpBitXor(struct arith_parse_state * ,token /*BITXOR*/ x1 ,proto /*expr*/ x2 ,proto /*expr*/ x3);

// CustomProduction UnOpAbsolute -> arith_grouping_expr
proto arith_custom_production_UnOpAbsolute(struct arith_parse_state * ,token /*ABSOLUTE*/ x1 ,proto /*expr*/ x2);

// CustomProduction UnOpNegate -> arith_grouping_expr
proto arith_custom_production_UnOpNegate(struct arith_parse_state * ,token /*NEGATE*/ x1 ,proto /*expr*/ x2);

// CustomProduction UnOpIncrement -> arith_grouping_expr
proto arith_custom_production_UnOpIncrement(struct arith_parse_state * ,token /*INCREMENT*/ x1 ,proto /*expr*/ x2);

// CustomProduction UnOpDecrement -> arith_grouping_expr
proto arith_custom_production_UnOpDecrement(struct arith_parse_state * ,token /*DECREMENT*/ x1 ,proto /*expr*/ x2);

// AssignProduction Parenthesised -> arith_grouping_expr
proto arith_assign_production_Parenthesised(struct arith_parse_state * ,token /*LPAREN*/ x1 ,proto /*expr*/ x2 ,token /*RPAREN*/ x3);

// CustomProduction FromInteger -> arith_grouping_expr
proto arith_custom_production_FromInteger(struct arith_parse_state * ,token /*INTEGER*/ x1);


#endif // ARITH_PRODUCTIONS_H_INCLUDED
