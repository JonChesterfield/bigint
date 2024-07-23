#include "arith.h"
#include "arith.production_tree.h"
#include "proto.h"

// arith doesn't bother building a tree so these are mostly stubs
proto_context arith_parse_state_get_tree_context(
    struct arith_parse_state* state)
{
  return state->context;
}

// memory management is dubious here, should this be copying in/out?
// parse tree expected things to be in an arean which is not presently the case
proto arith_parse_state_get_stored_tree(struct arith_parse_state* state)
{
  return state->stored;
}

void arith_parse_state_set_stored_tree(struct arith_parse_state* state, proto p)
{
  state->stored = p;
}

uint64_t arith_parse_state_list_production_identifier_fixup(
    struct arith_parse_state* state, uint64_t id)
{
  (void)state;
  return id;
}

// Declarations of functions used by assign, list productions
proto arith_production_failure(struct arith_parse_state* state)
{
  (void)state;
  return proto_create_invalid();
}

bool arith_production_is_failure(struct arith_parse_state* state, proto val)
{
  (void)state;
  return !proto_valid(state->context, val);
}
proto arith_production_sentinel(struct arith_parse_state* state)
{
  (void)state;
  return proto_sentinel();
}
bool arith_production_is_sentinel(struct arith_parse_state* state, proto val)
{
  (void)state;
  return proto_is_sentinel(val);
}
proto arith_production_make_token(struct arith_parse_state* state, uint64_t id,
                                  const char* value, size_t token_width)
{
  // No tokens
  (void)state;
  return proto_create_invalid();
}

proto arith_production_create_uninitialised(struct arith_parse_state* ctx,
                                            uint64_t id, uint64_t arity)
{
  // No lists
  (void)ctx;
  (void)id;
  (void)arity;
  return proto_create_invalid();
}

void arith_production_initialise_element(struct arith_parse_state* ctx,
                                         proto uninit, uint64_t idx, proto elt)
{
  (void)ctx;
  (void)uninit;
  (void)idx;
  (void)elt;
}
