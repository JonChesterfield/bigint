#include "arith.token.t"
// prefix regex for arith
const char* arith_token_prefix_regexes[arith_token_count] = {
  [arith_token_UNKNOWN] = "(|(&.(~0a))0a)",
  [arith_token_PLUS] = "(:(:6164)64)",
  [arith_token_MINUS] = "(:(:7375)62)",
  [arith_token_TIMES] = "(:(:6d75)6c)",
  [arith_token_DIVIDE] = "(:(:6469)76)",
  [arith_token_REMAINDER] = "(:(:7265)6d)",
  [arith_token_BITOR] = "(:6f72)",
  [arith_token_BITAND] = "(:(:616e)64)",
  [arith_token_BITXOR] = "(:(:786f)72)",
  [arith_token_ABSOLUTE] = "(:(:6162)73)",
  [arith_token_NEGATE] = "(:(:6e65)67)",
  [arith_token_INCREMENT] = "(:(:(:696e)63)72)",
  [arith_token_DECREMENT] = "(:(:(:6465)63)72)",
  [arith_token_INTEGER] = "(|30(:(:(|2d_)(|(|(|(|(|(|(|(|3132)33)34)35)36)37)38)39))(*(|(|(|(|(|(|(|(|(|3031)32)33)34)35)36)37)38)39))))",
  [arith_token_SPACE] = "20",
  [arith_token_NEWLINE] = "0a",
  [arith_token_CONTROL] = "(:(|(|(|(|(|(|40(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|4142)43)44)45)46)47)48)49)4a)4b)4c)4d)4e)4f)50)51)52)53)54)55)56)57)58)59)5a))21)23)24)25)26)(*(|(|(|(|(|(|40(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|(|4142)43)44)45)46)47)48)49)4a)4b)4c)4d)4e)4f)50)51)52)53)54)55)56)57)58)59)5a))21)23)24)25)26)))",
};

