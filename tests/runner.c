#include "../vendor/EvilUnit/EvilUnit.h"
MODULE(tests_runner)
{
  DEPENDS(test_absolute);
  DEPENDS(test_add);
  DEPENDS(test_bitwise_and);
  DEPENDS(test_bitwise_not);
  DEPENDS(test_decr);
  DEPENDS(test_div);
  DEPENDS(test_incr);
  DEPENDS(test_mul);
  DEPENDS(test_negate);
  DEPENDS(test_bitwise_or);
  DEPENDS(test_rem);
  DEPENDS(test_sub);
  DEPENDS(test_bitwise_xor);
}
