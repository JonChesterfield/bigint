#ifndef ARITH_PARSER_LEMON_T_INCLUDED
#define ARITH_PARSER_LEMON_T_INCLUDED

enum {
  arith_parser_lemon_type_align = 8,
  arith_parser_lemon_type_size = 72,
};
struct arith_parser_lemon_state {
    char _Alignas(arith_parser_lemon_type_align) data[arith_parser_lemon_type_size];
};

#endif
