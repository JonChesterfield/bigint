#include "arith.h"
#include "arith.production_tree.h"
#include "proto.h"

// arith doesn't bother building a tree so these are all stubs
proto_context arith_parse_state_get_tree_context(
    struct arith_parse_state* state)
{
  (void)state;
  return (proto_context){0};
}

// memory management is dubious here, parse tree expects things to be in an
// arena should this be copying in/out?
proto arith_parse_state_get_stored_tree(struct arith_parse_state* state)
{
  return state->stored;
}

void arith_parse_state_set_stored_tree(struct arith_parse_state* state, proto p)
{
  state->stored = p;
}

// Takes the ID from the grammar and returns the one to use to create the list,
// e.g. the argument
uint64_t arith_parse_state_list_production_identifier_fixup(
    struct arith_parse_state*, uint64_t id);

// Declarations of functions used by assign, list productions
proto arith_production_failure(struct arith_parse_state* state)
{
  (void)state;
  return proto_create_invalid();
}

bool arith_production_is_failure(struct arith_parse_state* state, proto val)
{
  (void)state;
  return !proto_valid(val);
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
  return proto_create_invalid();
}
void arith_production_initialise_element(struct arith_parse_state* ctx,
                                         proto uninit, uint64_t idx, proto elt)
{
}
