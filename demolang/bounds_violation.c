#include "../vendor/EvilUnit/EvilUnit.h"
#include <stdio.h>


// Currently wired to call this when a bound violation is detected
void libtommath_on_bounds_violation(const char *what)
{
  fprintf(stderr, "tommath bounds violation! [%s]\n", what);
  
  // Don't have a great way to detect whether this is available at present
#ifdef  EVILUNIT_CONTRACT_SETJUMP_IMPL
  evilunit_contract_longjump();
#else
  __builtin_trap();
#endif
}

