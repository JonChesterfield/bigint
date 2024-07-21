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
  arith_production_assign_production_Parenthesised = 6,
  arith_production_custom_production_FromInteger = 7,
};
enum { arith_production_count = 8 };
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

// AssignProduction Parenthesised -> arith_grouping_expr
proto arith_assign_production_Parenthesised(struct arith_parse_state * ,token /*LPAREN*/ x1 ,proto /*expr*/ x2 ,token /*RPAREN*/ x3);

// CustomProduction FromInteger -> arith_grouping_expr
proto arith_custom_production_FromInteger(struct arith_parse_state * ,token /*INTEGER*/ x1);


#endif // ARITH_PRODUCTIONS_H_INCLUDED
