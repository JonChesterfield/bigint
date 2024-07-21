#ifndef ARITH_PARSER_LEMON_H_INCLUDED
#define ARITH_PARSER_LEMON_H_INCLUDED

#include "../tools/token.h"

// Declaration of struct arith_parse_state
#include "arith.parser.h"
#include "arith.production_tree.h"

struct arith_parser_lemon_state;
typedef struct arith_parser_lemon_state arith_parser_lemon_state;

proto arith_parser_lemon_tree(struct arith_parse_state *context, arith_parser_lemon_state *a);

// true success, false if it hit a failure
bool arith_parser_lemon_parse(struct arith_parse_state *context, arith_parser_lemon_state *a, int id, token t);
void arith_parser_lemon_finalize(arith_parser_lemon_state *a);
void arith_parser_lemon_initialize(arith_parser_lemon_state *a);

// TODO: This should take a const unsigned char*, size_t pair and create a
// forwarding wrapper for the cstr, currently have extra implementations to allow
// passing non-null-terminated data which are essentially identical to this generated one
proto arith_parser_lemon_parse_cstr(struct arith_parse_state *context, const char * data);

#if __STDC_HOSTED__
int arith_parser_lemon_type_header(void);
void arith_parser_lemon_trace_on(void);
void arith_parser_lemon_trace_off(void);
static inline void arith_parser_lemon_trace_set(bool t)
{
  if (t)
  {
    arith_parser_lemon_trace_on();
  }
  else
  {
    arith_parser_lemon_trace_off();
  }
}
#endif

#endif // ARITH_PARSER_LEMON_H_INCLUDED
