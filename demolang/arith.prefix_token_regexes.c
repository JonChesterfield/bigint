#include "arith.token.t"
// prefix regex for arith
const char* arith_token_prefix_regexes[arith_token_count] = {
  [arith_token_UNKNOWN] = "(|(&.(~0a))0a)",
  [arith_token_PLUS] = "(:(:6164)64)",
  [arith_token_MINUS] = "(:(:7375)62)",
  [arith_token_TIMES] = "(:(:6d75)6c)",
  [arith_token_DIVIDE] = "(:(:6469)76)",
  [arith_token_REMAINDER] = "(:(:7265)6d)",
  [arith_token_INTEGER] = "(:(|2d_)(:(|(|(|(|(|(|(|(|(|3031)32)33)34)35)36)37)38)39)(*(|(|(|(|(|(|(|(|(|3031)32)33)34)35)36)37)38)39))))",
  [arith_token_LPAREN] = "28",
  [arith_token_RPAREN] = "29",
  [arith_token_WHITESPACE] = "(:(|(|(|(|(|200c)0a)0d)09)0b)(*(|(|(|(|(|200c)0a)0d)09)0b)))",
};

