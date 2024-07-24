#include "../vendor/EvilUnit/EvilUnit.h"
MODULE(tests_runner)
{
  DEPENDS(test_abs);
  DEPENDS(test_add);
  DEPENDS(test_and);
  DEPENDS(test_decr);
  DEPENDS(test_div);
  DEPENDS(test_incr);
  DEPENDS(test_mul);
  DEPENDS(test_neg);
  DEPENDS(test_or);
  DEPENDS(test_rem);
  DEPENDS(test_sub);
  DEPENDS(test_xor);
}
