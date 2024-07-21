#include "arith.production_tree.h"

// arith implementation uses non-default types, implemented elsewhere


bool arith_parse_state_is_failure(struct arith_parse_state * context)
{
  proto state = arith_parse_state_get_stored_tree(context);
  return arith_production_is_failure(context, state);
}

bool arith_parse_state_is_sentinel(struct arith_parse_state * context)
{
  proto state = arith_parse_state_get_stored_tree(context);
  return arith_production_is_sentinel(context, state);
}
