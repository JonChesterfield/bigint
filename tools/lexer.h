#ifndef LEXER_INSTANCE_H_INCLUDED
#define LEXER_INSTANCE_H_INCLUDED

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "lexer.t"

// A lexer instance is specified by N regular expressions, the convention
// that longer matches are preferred to shorter ones, and when two regex
// both match the same length, the one listed earlier in the definition wins
//
// As an implementation detail, index '0' is reserved for unknown/non-match
// so in effect the regexes are indexed from 1

// The defines here can disable generation of lexers at the site level,
// e.g. for when an external library is not available
// A define of 0 will disable the lexer, a missing define will enable it

// Uses regex.h from the posix libc extensions
#ifndef LEXER_POSIX_ENABLE
#define LEXER_POSIX_ENABLE 1
#endif

// Enable RE2 lexer if the headers are available
#if __has_include(<re2/re2.h>) && __has_include(<re2/set.h>)
#ifndef LEXER_RE2_ENABLE
#define LEXER_RE2_ENABLE 1
#endif
#else
#ifndef LEXER_RE2_ENABLE
#define LEXER_RE2_ENABLE 0
#endif
#if LEXER_RE2_ENABLE
#error "LEXER RE2 enabled but headers are not found"
#endif
#endif

// Except currently disabling it as it makes valgrind output hard to read
#undef LEXER_RE2_ENABLE
#define LEXER_RE2_ENABLE 0

// Build a lexer using re2c program
// Test should ideally reflect whether re2c is available or not
#ifndef LEXER_RE2C_ENABLE
#define LEXER_RE2C_ENABLE 1
#endif

// An interpreter for regex, implemented in this repo
#ifndef LEXER_INTERP_ENABLE
#define LEXER_INTERP_ENABLE 1
#endif

// Staged ascii to prefix compile followed by interpreting the prefix
#ifndef LEXER_A2PI_ENABLE
#define LEXER_A2PI_ENABLE 1
#endif

// ascii to prefix to C state machine
#ifndef LEXER_A2PC_ENABLE
#define LEXER_A2PC_ENABLE 1
#endif

// A debugging option, runs all the other lexers and fails if they disagree
#ifndef LEXER_MULTI_ENABLE
#define LEXER_MULTI_ENABLE 1
#endif

// Not sure how best to specify the interface.
// Currently nothing implements these exact symbols, but posix/multi etc
// implement ones with related names and the language instantiations
// use similar interfaces e.g. lexer_t {$lang}_lexer_create(void);
// but where the regexes array is behind the interface.
// Instances of lexer_function_table_t might be the right choice
#if 0
lexer_t lexer_t_create(void);
void lexer_t_destroy(lexer_t);
bool lexer_t_valid(lexer_t l);  // create succeeded
lexer_token_t lexer_iterator_t_step(lexer_t, lexer_iterator_t *);
size_t lexer_regex_count(lexer_t l);
lexer_match_t lexer_single_regex_bytes_matching(lexer_t l, size_t regex_idx,
                                                lexer_iterator_t iter);
lexer_match_t lexer_sequence_regex_bytes_matching(lexer_t l, lexer_iterator_t iter);

#endif

static inline lexer_iterator_t lexer_iterator_t_create(const char *bytes,
                                                       size_t len_bytes)
{
  return (lexer_iterator_t){.cursor = bytes, .end = bytes + len_bytes};
}
static inline bool lexer_iterator_t_empty(lexer_iterator_t it)
{
  return it.cursor == it.end;
}
static inline lexer_iterator_t lexer_iterator_t_increment(lexer_iterator_t iter,
                                                          size_t by)
{
  return (lexer_iterator_t){.cursor = iter.cursor + by, .end = iter.end};
}

static inline bool lexer_token_t_empty(lexer_token_t token)
{
  return token.width == 0;
}

static inline void lexer_token_dump(lexer_token_t s)
{
  printf("<LexerToken ID = \"%zu\" value = \"", s.id);
  const char *c = s.value;
  size_t w = s.width;
  for (size_t i = 0; i < w; i++)
    {
      printf("%c", *c++);
    }

  printf("\" />\n");
}

static inline lexer_match_t lexer_sequence_regex_bytes_matching_from_single_regexes(
    lexer_t l, size_t count, lexer_iterator_t iter, 
    lexer_match_t (*const single_regex_bytes_matching)(lexer_t, size_t regex_idx,
                                                lexer_iterator_t))
{
  assert(!lexer_iterator_t_empty(iter));
  assert(count > 0);

  size_t N = count;


  lexer_match_t zeroth_matches = single_regex_bytes_matching(l, 0, iter);
  if (zeroth_matches.regex_id != 0)
    {
      size_t width = iter.end - iter.cursor;
      printf(
          "Internal error. Zeroth regex did not match %s 0x%x. Iterator width "
          "%zu.\n",
          iter.cursor, (int)iter.cursor[0], width);
      if (width > 8) width = 8;
      for (size_t i = 0; i < width; i++)
        {
          printf("Char [%zu] = 0x%x (%c) \n", i, iter.cursor[i],
                 iter.cursor[i]);
        }
    }
  assert(zeroth_matches.regex_id == 0);

  // Looking for longest match wins, with earliest match on tie break
  lexer_token_t result = {
      .id = 0,
      .value = "", // dead
      .width = 1,
  };

  for (size_t i = 1; i < N; i++)
    {
      lexer_match_t m = single_regex_bytes_matching(l, i, iter);
      if (m.regex_id != i) continue; // no match

      bool is_first_match = result.id == 0;
      bool is_longer_match = m.bytes_count > result.width;
      if (is_first_match | is_longer_match)
        {
          result.id = i;
          result.width = m.bytes_count;
        }
    }

  return (lexer_match_t) {.regex_id = result.id, .bytes_count = result.width};
}

// The overall lexer implementation is equivalent to trying each single regex in
// turn Some lexers use this as their implementation, all (should) be consistent
// with this calculation.
static inline lexer_token_t lexer_iterator_step_from_single_regexes(
    lexer_t l, lexer_iterator_t *iter, size_t count,
    lexer_match_t (*const single_regex_bytes_matching)(lexer_t, size_t regex_idx,
                                                lexer_iterator_t))
{
  assert(iter);
  assert(!lexer_iterator_t_empty(*iter));
  assert(count > 0);

  lexer_match_t match = lexer_sequence_regex_bytes_matching_from_single_regexes(l, count, *iter, single_regex_bytes_matching);
  assert (match.regex_id < count); // zero/unknown, if nothing better
  
  lexer_token_t result = {
      .id = match.regex_id,
      .value = iter->cursor,
      .width = match.bytes_count,
  };

  iter->cursor += match.bytes_count;
  
  return result;
}

#endif
