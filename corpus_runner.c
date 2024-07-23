#include "corpus.h"
#include "demolang/calc.h"
#include "vendor/EvilUnit/EvilUnit.h"

#if 1
EVILUNIT_MAIN_MODULE()
{
  DEPENDS(corpus);
}
#else
int main()
{
  int badcount = 0;
  for (unsigned long i = 0; i < corpus_cases_count; i++)
    {
      int rc = calclib((const unsigned char*) corpus_cases[i],
                       __builtin_strlen(corpus_cases[i]),
                       false);
      if (rc != 0)
        {
          badcount++;
        }
    }
  if (badcount)
    return 1;

  return 0;
}
#endif
