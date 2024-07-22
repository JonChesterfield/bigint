#ifndef LEXER_RE2C_H_INCLUDED
#define LEXER_RE2C_H_INCLUDED

#include "lexer.h"

#ifndef NDEBUG
#include <stdio.h>
#include <stdlib.h>
#endif

#if LEXER_RE2C_ENABLE
static inline
lexer_t lexer_re2c_create(size_t N, const char** regexes);
static inline
void lexer_re2c_destroy(lexer_t lex);
static inline
bool lexer_re2c_valid(lexer_t lex);
// Iterator step is generated per-regex-list for re2c


// Moved the implementation into the header. Not planning on
// that as the permanent solution, but 
typedef struct
{
#ifndef NDEBUG
  enum lexer_engines engine;
#else
  char unused;
#endif
} lexer_re2c_lexer;

static void lexer_re2c_lexer_set_engine(lexer_re2c_lexer* l)
{
#ifndef NDEBUG
  l->engine = lexer_engines_re2c;
#else
  (void)l;
#endif
}

static void lexer_re2c_lexer_check_engine(lexer_re2c_lexer* l)
{
#ifndef NDEBUG
  if (l != NULL)
    {
      unsigned num = l->engine;
      if (num != lexer_engines_re2c)
        {
          fprintf(stderr,
                  "Invalid magic number (%u) for lexer.re2c, aborting\n", num);
          abort();
        }
    }
#else
  (void)l;
#endif
}


static lexer_t lexer_re2c_from_re2c(lexer_re2c_lexer* l)
{
  lexer_re2c_lexer_check_engine(l);
  return (lexer_t){.data = (void*)l};
}

static lexer_re2c_lexer* lexer_re2c_to_re2c(lexer_t l)
{
  lexer_re2c_lexer* lexer = (lexer_re2c_lexer*)l.data;
  lexer_re2c_lexer_check_engine(lexer);
  return lexer;
}

lexer_t lexer_re2c_create(size_t N, const char** regexes)
{
  (void)N;
  (void)regexes;
  static lexer_re2c_lexer only = {0};
  lexer_re2c_lexer_set_engine(&only);
  lexer_re2c_lexer_check_engine(&only);
  return lexer_re2c_from_re2c(&only);
}

void lexer_re2c_destroy(lexer_t l)
{
  lexer_re2c_lexer* lexer = lexer_re2c_to_re2c(l);
  lexer_re2c_lexer_check_engine(lexer);
  (void)lexer;
}

bool lexer_re2c_valid(lexer_t l)
{
  lexer_re2c_lexer* lexer = lexer_re2c_to_re2c(l);
  (void)lexer;
  return true;
}


#endif
#endif
