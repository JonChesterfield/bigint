#include "arith.parser.h"


_Static_assert((arith_grouping_program - arith_token_count == 0), "");

// Names table
const char* arith_grouping_names[arith_grouping_count - arith_token_count] = {
  [arith_grouping_program - arith_token_count] = "program",
  [arith_grouping_expr - arith_token_count] = "expr",
};
