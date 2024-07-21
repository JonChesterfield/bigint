#include "arith.productions.h"
#include "arith.lexer.h"
#include "arith.parser.h"
#include "../tools/stack.libc.h"

// AssignProduction expression_to_program -> arith_grouping_program
proto arith_assign_production_expression_to_program(struct arith_parse_state * context, proto /*expr*/ x1)
{
  proto R = x1;
  return R;
}

// AssignProduction Parenthesised -> arith_grouping_expr
proto arith_assign_production_Parenthesised(struct arith_parse_state * context, token /*LPAREN*/ x1, proto /*expr*/ x2, token /*RPAREN*/ x3)
{
  (void)x1;
  proto R = x2;
  (void)x3;
  return R;
}
