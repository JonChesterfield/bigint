#include "../vendor/EvilUnit/EvilUnit.h"
MODULE(tests_memchk_runner)
{
  DEPENDS(test_memchk_abs);
  DEPENDS(test_memchk_add);
  DEPENDS(test_memchk_and);
  DEPENDS(test_memchk_decr);
  DEPENDS(test_memchk_div);
  DEPENDS(test_memchk_incr);
  DEPENDS(test_memchk_mul);
  DEPENDS(test_memchk_neg);
  DEPENDS(test_memchk_or);
  DEPENDS(test_memchk_rem);
  DEPENDS(test_memchk_sub);
  DEPENDS(test_memchk_xor);
}
