#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>  // size_t
#include <stdio.h>
#include <string.h>

#include "ascii.h"

#ifdef __cplusplus
extern "C" {
#endif

// Tokens are assigned values in [1, N)
// with 0 used as a default catch/all
// Passing the token name around is messy and the integer needs
// to be passed to lemon's parser anyway, so storing the string
// directly works out better.
// Might want to reconsider this, in particular it's ugly to
// retrieve the integer from the string  
// Maybe generating an explicit enum header which is consistency
// checked against the defines used by lemon is the answer (along
// with maps to the string names)

typedef struct
{
  // Non-owning pointer into a null terminated string, probably
  // a statically allocated one
  // If writing this as xml, name needs to be a valid element
  const char *name;

  // Non-owning pointers into the contiguous memory representing whatever
  // is being lexed. The re2 regex engine works on a string view based on
  // char*.
  const char *value;  // width chars, generally not nul terminated
  size_t width;
} token;

static inline token token_create(const char *name, const char *value_start,
                                 size_t value_width)
{
  return (token){
      .name = name,
      .value = value_start,
      .width = value_width,
  };
}

static inline token token_create_novalue(const char *name)
{
  static const char empty[1] = {'\0'};
  return token_create(name, empty, 0);
}

static inline const char* token_value(token s) { return s.value; }
static inline size_t token_width(token s) { return s.width; }

static inline bool token_empty(token s) { return token_width(s) == 0; }

static inline bool token_equal(token x, token y)
{
  if (x.name != y.name)
    {
      return false;
    }
  size_t w = token_width(x);
  if (w != token_width(y))
    {
      return false;
    }
  bool eq = true;
  for (size_t i = 0; i < w; i++)
    {
      eq &= (x.value[i] == (y.value[i]));
    }
  return eq;
}

static inline bool token_chars_all_alphanumeric(token s)
{
  size_t w = token_width(s);
  bool all = true;
  for (size_t i = 0; i < w; i++)
    {
      char c = s.value[i];
      all &= ascii_char_to_type(c) == alphanumeric;
    }
  return all;
}

static inline void token_as_xml(FILE *f, token s)
{
  fprintf(f, "<%s value = \"", s.name);
  fwrite(s.value, 1, token_width(s), f);
  fprintf(f, "\" />");
}

static inline void token_dump(token s)
{
  printf("<Token name = \"%s\" value = \"", s.name);
  const char *c = s.value;
  size_t w = token_width(s);
  for (size_t i = 0; i < w; i++)
    {
      printf("%c", *c++);
    }

  printf("\" />\n");
}

static inline void token_named_dump(token s, const char **token_names)
{
  (void)token_names;
  token_as_xml(stdout, s);
  fprintf(stdout, "\n");
}

// xml quoting is messier than this but it's a start
// element/attribute names have different restrictions to values
static inline bool token_requires_hex(token s)
{
  size_t w = token_width(s);
  for (size_t i = 0; i < w; i++)
    {
      char c = s.value[i];
      if (ascii_char_to_type(c) == alphanumeric)
        {
          continue;
        }
      switch (c)
        {
          case '_':
          case '-':
          case ' ':
          case '.':
            break;
          default:
            // Unknown thing, hex escape it
            return true;
        }
    }
  return false;
}

#ifdef __cplusplus
}
#endif

#endif
