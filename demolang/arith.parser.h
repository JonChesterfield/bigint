#ifndef ARITH_PARSER_DECLARATIONS_H_INCLUDED
#define ARITH_PARSER_DECLARATIONS_H_INCLUDED

#include "arith.lexer.h"
#include "arith.production_tree.h"

// Enumeration
enum arith_grouping {
  arith_grouping_program = arith_token_count,
  arith_grouping_expr = arith_token_count + 1,
  arith_grouping_integer = arith_token_count + 2,
  arith_grouping_control_block = arith_token_count + 3,
};

enum { arith_grouping_count = arith_token_count + 4, };

static inline bool arith_parser_identifier_valid_grouping(uint64_t id)
{
  return (id >= arith_token_count) && (id < arith_grouping_count);
}

// Names table
extern const char* arith_grouping_names[arith_grouping_count - arith_token_count];

#endif // ARITH_PARSER_DECLARATIONS_H_INCLUDED
