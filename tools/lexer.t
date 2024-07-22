#ifndef LEXER_INSTANCE_T_INCLUDED
#define LEXER_INSTANCE_T_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// The id in the token is an index into the sequence of regexes
typedef struct
{
  size_t id;
  const char *value;
  size_t width;
} lexer_token_t;

// Each lexer uses the same iterator interface
typedef struct
{
  const char *cursor;
  const char *end;
} lexer_iterator_t;

typedef struct
{
  void *data;
} lexer_t;

enum lexer_engines
{
  lexer_engines_unused = 0,
  lexer_engines_multi,
  lexer_engines_posix,
  lexer_engines_re2,
  lexer_engines_re2c,
  lexer_engines_a2pi,
  lexer_engines_a2pc,
  lexer_engines_interp,
  lexer_engines_handwritten,
};


typedef struct
{
  size_t regex_id; // [0 regex_count()], returns regex_count() on no match
  size_t bytes_count;
} lexer_match_t;

typedef struct
{
  const char * const name;
  lexer_t (*const create)(void);
  void (*const destroy)(lexer_t);
  bool (*const valid)(lexer_t);
  lexer_token_t (*const iterator_step)(lexer_t, lexer_iterator_t *);
  size_t (*const regex_count)(lexer_t);
  lexer_match_t (*const single_regex_bytes_matching)(lexer_t, size_t regex_idx, lexer_iterator_t);
  lexer_match_t (*const sequence_regex_bytes_matching)(lexer_t, lexer_iterator_t);
} lexer_function_table_t;

#endif
