#include "arith.productions.h"
#include "arith.lexer.h"
#include "arith.parser.h"
#include "../tools/stack.libc.h"

// AssignProduction expr_to_program -> arith_grouping_program
proto arith_assign_production_expr_to_program(struct arith_parse_state * context, proto /*expr*/ x1)
{
  proto R = x1;
  return R;
}
