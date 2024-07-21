#ifndef ARITH_PRODUCTION_TREE_H_INCLUDED
#define ARITH_PRODUCTION_TREE_H_INCLUDED
#include "arith.parse_tree.h"
// Functions called by the generated productions


// The parse state is opaque from the perspective of the parser implementation
struct arith_parse_state;

// Typedefs, can remove once regex is ast based instead of ptree
typedef proto_context arith_tree_context_type;
typedef proto arith_tree_type;

// Access underlying values stored in the parse state
proto_context arith_parse_state_get_tree_context(struct arith_parse_state*);

proto arith_parse_state_get_stored_tree(struct arith_parse_state*);
void arith_parse_state_set_stored_tree(struct arith_parse_state*, proto);

// Takes the ID from the grammar and returns the one to use to create the list, e.g. the argument
uint64_t arith_parse_state_list_production_identifier_fixup(struct arith_parse_state*, uint64_t id);


// Declarations of functions used by assign, list productions
proto arith_production_failure(struct arith_parse_state *);
bool arith_production_is_failure(struct arith_parse_state *, proto val);
proto arith_production_sentinel(struct arith_parse_state *);
bool arith_production_is_sentinel(struct arith_parse_state *, proto val);
proto arith_production_make_token(struct arith_parse_state *, uint64_t id, const char *value, size_t token_width);
proto arith_production_create_uninitialised(struct arith_parse_state *, uint64_t id, uint64_t arity);
void arith_production_initialise_element(struct arith_parse_state *, proto uninit, uint64_t idx, proto elt);

// Derived functions used to track the state
bool arith_parse_state_is_failure(struct arith_parse_state *);
bool arith_parse_state_is_sentinel(struct arith_parse_state *);
#endif // ARITH_PRODUCTION_TREE_H_INCLUDED
