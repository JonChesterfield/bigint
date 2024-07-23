#ifndef ARITH_LEXER_DECLARATIONS_H_INCLUDED
#define ARITH_LEXER_DECLARATIONS_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>



// Lexer declaration
#include "../tools/lexer.h"
enum arith_token;

// The default lexer for arith
lexer_t arith_lexer_create(void);
void arith_lexer_destroy(lexer_t);
bool arith_lexer_valid(lexer_t);
lexer_token_t arith_lexer_iterator_step(lexer_t, lexer_iterator_t *);
size_t arith_lexer_regex_count(lexer_t l);
lexer_match_t arith_lexer_single_regex_bytes_matching(
  lexer_t l, size_t regex_idx, lexer_iterator_t iter);
lexer_match_t arith_lexer_sequence_regex_bytes_matching(
  lexer_t l, lexer_iterator_t iter);

static const lexer_function_table_t arith_lexer_table = {
  .name = "arith_lexer",
  .create = arith_lexer_create,
  .destroy = arith_lexer_destroy,
  .valid = arith_lexer_valid,
  .iterator_step = arith_lexer_iterator_step,
  .regex_count = arith_lexer_regex_count,
  .single_regex_bytes_matching = arith_lexer_single_regex_bytes_matching,
  .sequence_regex_bytes_matching = arith_lexer_sequence_regex_bytes_matching,
};

bool arith_lexer_discard_token(enum arith_token);
static inline bool arith_lexer_identifier_valid_token(uint64_t);
// arith_token_UNKNOWN if the whole C string does not lex to a token
enum arith_token arith_lexer_try_string_to_token(const lexer_function_table_t *tab, lexer_t lex, const char * bytes, size_t N);
// True iff the entire c string lexes successfully to token with this type
bool arith_lexer_string_lexes_to_token(const char *str, enum arith_token req);
lexer_summarise_res_t arith_lexer_summarise_string(const char * bytes, size_t N);

// Enumeration
#include "arith.token.t"

static inline bool arith_lexer_identifier_valid_token(uint64_t id)
{
  return (id > arith_token_UNKNOWN) && (id < arith_token_count);
}

// Names table
extern const char*arith_token_names[arith_token_count];

// Regex table
extern const char*arith_token_regexes[arith_token_count];

// Prefix regex table
extern const char*arith_token_prefix_regexes[arith_token_count];

// Available lexer instantiations
// Engine posix disabled by the language spec
#define ARITH_LEXER_POSIX_ENABLE 0
// Engine re2 disabled by the language spec
#define ARITH_LEXER_RE2_ENABLE 0
// Engine re2c disabled by the language spec
#define ARITH_LEXER_RE2C_ENABLE 0
// Engine a2pi disabled by the language spec
#define ARITH_LEXER_A2PI_ENABLE 0



// Engine a2pc enabled by the language spec
#if !defined(LEXER_A2PC_ENABLE) || LEXER_A2PC_ENABLE
#define ARITH_LEXER_A2PC_ENABLE 1
#else
#define ARITH_LEXER_A2PC_ENABLE 0
#endif
      
#if ARITH_LEXER_A2PC_ENABLE
lexer_t arith_lexer_a2pc_create(void);
void arith_lexer_a2pc_destroy(lexer_t);
bool arith_lexer_a2pc_valid(lexer_t);
lexer_token_t arith_lexer_a2pc_iterator_step(lexer_t, lexer_iterator_t *);
size_t arith_lexer_a2pc_regex_count(lexer_t l);
lexer_match_t arith_lexer_a2pc_single_regex_bytes_matching(
  lexer_t l, size_t regex_idx, lexer_iterator_t iter);
lexer_match_t arith_lexer_a2pc_sequence_regex_bytes_matching(
  lexer_t l, lexer_iterator_t iter);


static const lexer_function_table_t arith_lexer_a2pc_table = {
  .name = "arith_lexer_a2pc",
  .create = arith_lexer_a2pc_create,
  .destroy = arith_lexer_a2pc_destroy,
  .valid = arith_lexer_a2pc_valid,
  .iterator_step = arith_lexer_a2pc_iterator_step,
  .regex_count = arith_lexer_a2pc_regex_count,
  .single_regex_bytes_matching = arith_lexer_a2pc_single_regex_bytes_matching,
  .sequence_regex_bytes_matching = arith_lexer_a2pc_sequence_regex_bytes_matching,
};
#endif //  ARITH_LEXER_A2PC_ENABLE

// Engine interp disabled by the language spec
#define ARITH_LEXER_INTERP_ENABLE 0
// Engine handwritten disabled by the language spec
#define ARITH_LEXER_HANDWRITTEN_ENABLE 0
// Engine multi disabled by the language spec
#define ARITH_LEXER_MULTI_ENABLE 0


#endif // ARITH_LEXER_DECLARATIONS_H_INCLUDED
