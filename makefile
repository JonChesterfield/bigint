.SUFFIXES:
MAKEFLAGS += -r -j$(shell nproc)
.SECONDARY:
.SUFFIXES:

SHELL = sh -xv

SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

ifeq ($(origin CC),default)
CC = clang
endif
ifeq ($(origin CXX),default)
CXX = clang++
endif

CFLAGS ?= -std=c99 -Wall -O1 -g -gdwarf-4 -Wno-unknown-attributes
LDFLAGS ?=


# make help looks through this makefile for ## annotations
.PHONY: help

.PHONY: all
all:: ## Fetch all code and build everything

.PHONY: fetch
fetch:: ## Download code from the web

.PHONY: build
build:: ## Compile everything

.PHONY: clean
clean:: ## Delete non-downloaded files

.PHONY: deepclean
deepclean:: ## Remove everything, restore to clean checkout

.PHONY: vendor
vendor:: ## Derive vendored source files from fetched files

# Top level dependencies
build::	vendor
all::	build
deepclean:: clean

# Downloading extra source from the internet during the build is
# optional, can make fetch, copy the files somewhere else, make build
# All downloaded files go into FETCH_DIR
FETCH_DIR := fetch
include fetch.mk
deepclean::
	rm -rf $(FETCH_DIR)


# Copy / edit files from fetch to create the ones under vendor
VENDOR_DIR := vendor
include vendor.mk
VENDOR_DIR_OBJ := .$(VENDOR_DIR).O
deepclean:: vendorclean
clean::
	@rm -rf $(VENDOR_DIR_OBJ)

vendorclean::
	@rm -rf $(VENDOR_DIR)


# Build each C file under vendor into a corresponding object file, depending on all headers
# under vendor (i.e. quite coarse grained dependency tracking)
VENDOR_OBJ := $(VENDOR_SRC:$(VENDOR_DIR)/%.c=$(VENDOR_DIR_OBJ)/%.o)

# The tree structure mirrors the source, make whatever directories are required
# If moving the mkdir under a dedicated target, check make make still reports nothing to do
VENDOR_OBJ_DIR_LIST := $(sort $(VENDOR_DIR_OBJ) $(dir $(VENDOR_OBJ)))

$(VENDOR_OBJ):	$(VENDOR_DIR_OBJ)/%.o:	$(VENDOR_DIR)/%.c $(VENDOR_HDR)
	@mkdir -p $(VENDOR_OBJ_DIR_LIST)
	@$(CC) $(CFLAGS) $< -c -o $@



VENDOR_LUA_OBJ := $(filter-out $(VENDOR_DIR_OBJ)/lua/luac.o,$(VENDOR_LUA_SRC:$(VENDOR_DIR)/%.c=$(VENDOR_DIR_OBJ)/%.o))
lua: $(VENDOR_LUA_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ -lm # no ldflags, don't want to link in a fuzzer
clean::
	@rm -f lua

VENDOR_LIBTOMMATH_OBJ := $(VENDOR_LIBTOMMATH_SRC:$(VENDOR_DIR)/%.c=$(VENDOR_DIR_OBJ)/%.o)
.vendor.O/libtommath.o: $(VENDOR_LIBTOMMATH_OBJ)
	ld -r $^ -o $@


VENDOR_LIBTOMMATH_CXX_OBJ := $(VENDOR_LIBTOMMATH_SRC:$(VENDOR_DIR)/%.c=$(VENDOR_DIR_OBJ)/%.cpp.o)

$(VENDOR_LIBTOMMATH_CXX_OBJ):	$(VENDOR_DIR_OBJ)/%.cpp.o:	$(VENDOR_DIR)/%.c $(VENDOR_HDR)
	@mkdir -p $(VENDOR_OBJ_DIR_LIST)
	@$(CXX) -xc++ -Wall $< -c -o $@


build::	$(VENDOR_OBJ) .vendor.O/libtommath.o $(VENDOR_LIBTOMMATH_CXX_OBJ)


PROTO_SRC := proto_impl.c proto.c proto_derived.c proto_memory_check.c
PROTO_OBJ := $(PROTO_SRC:%.c=$(VENDOR_DIR_OBJ)/%.o)

$(PROTO_OBJ):	$(VENDOR_DIR_OBJ)/%.o:	%.c proto.h proto_memory_check.h $(VENDOR_HDR)
	@mkdir -p $(VENDOR_DIR_OBJ)
	@$(CC) $(CFLAGS) $< -c -o $@



proto:	$(PROTO_OBJ) $(VENDOR_LIBTOMMATH_OBJ)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
clean::
	@rm -f proto

build::	proto

proto_memory_check.h:	lua api.lua
	./lua api.lua memory_header proto proto proto_context > $@
proto_memory_check.c:	lua api.lua
	./lua api.lua memory_source proto proto proto_context > $@
clean::
	rm -f proto_memory_check.?

DEMOLANG_DIR := demolang
DEMOLANG_DIR_OBJ := .$(DEMOLANG_DIR).O
include demolang/files.mk
DEMOLANG_SRC := $(addprefix demolang/,$(filter %.c,$(DEMOLANG_FILES)))
DEMOLANG_HDR := $(addprefix demolang/,$(filter %.h,$(DEMOLANG_FILES)))
DEMOLANG_OBJ := $(DEMOLANG_SRC:$(DEMOLANG_DIR)/%.c=$(DEMOLANG_DIR_OBJ)/%.o)

$(DEMOLANG_DIR_OBJ)/%.o:	$(DEMOLANG_DIR)/%.c $(DEMOLANG_HDR) proto.h $(VENDOR_HDR)  proto_memory_check.h proto.h
	@mkdir -p $(DEMOLANG_DIR_OBJ)
	@$(CC) $(CFLAGS) $< -c -o $@

demolang::	$(DEMOLANG_OBJ)


SEEDFILES := $(wildcard seedfiles/*)
MORE_FUZZFILES := $(wildcard /scratch/jon/fuzz/corpus/*)


# This file is working around makefile passing many files to a single
# shell invocation which then falls over
$(shell mkdir -p $(VENDOR_DIR_OBJ))
CAT_FUZZFILES := $(VENDOR_DIR_OBJ)/all_fuzzfiles
$(file >$(CAT_FUZZFILES))
$(foreach V,$(MORE_FUZZFILES),$(file >>$(CAT_FUZZFILES),$(file <$V)))


FUZZ_FILES_DIR := $(SELF_DIR)/fuzzfiles/
clean::
	@rm -rf $(CAT_FUZZFILES) fuzzfiles


EXTRACT_FILES_DIR := $(SELF_DIR)/extractfiles/
include extractfiles/files.mk
clean::
	@rm -rf $(CAT_EXTRACTFILES) extractfiles

ifeq (,$(wildcard extractfiles/files.mk))
extractfiles/files.mk: extract.awk $(CAT_EXTRACTFILES)
	@mkdir -p extractfiles
	@gawk --lint -f extract.awk extractfiles/ $(SEEDFILES) $(CAT_FUZZFILES)
endif


EXTRACT_SOURCE := $(addprefix extractfiles/,$(extract_files))

TESTCASE_SOURCE := $(addprefix testcases/,$(extract_files))

# Calculates the answer python expects for the given arithmetic
$(TESTCASE_SOURCE): testcases/%: extractfiles/% extractfiles/files.mk testcases.py
	@mkdir -p testcases
	python3 testcases.py $< > $@

clean::
	@rm -f $(TESTCASE_SOURCE)

SIMPLE_PYTHON := $(addprefix python/test_,$(addsuffix .py,$(extract_files)))

clean::
	@rm -rf $(SIMPLE_PYTHON) python/__pycache__ __pycache__

$(SIMPLE_PYTHON):	python/test_%.py: testcases/% | python/gen.awk extractfiles/files.mk
	gawk -f python/gen.awk $< > $@

.PHONY: test_python
test_python: ## Run test cases through python interpreter
test_python: $(SIMPLE_PYTHON) python/gen.awk
	python3 -m unittest discover python -v


SIMPLE_TESTS := $(addprefix tests/test_,$(addsuffix .c,$(extract_files)))


tests/main.c:
	@echo "#include \"../vendor/EvilUnit/EvilUnit.h\"" > $@
	@echo "MAIN_MODULE()" >> $@
	@echo "{" >> $@
	@echo "  DEPENDS(tests_runner);" >> $@
	@echo "}" >> $@


$(SIMPLE_TESTS):	tests/test_%.c: testcases/% tests/gen.awk extractfiles/files.mk
	gawk -f tests/gen.awk $< > $@


SIMPLE_TESTS_SRC := $(SIMPLE_TESTS) tests/runner.c tests/main.c
clean::
	rm -f $(SIMPLE_TESTS) tests/main.c


SIMPLE_TESTS_OBJ := $(SIMPLE_TESTS_SRC:tests/%.c=$(VENDOR_DIR_OBJ)/tests/%.o)

$(SIMPLE_TESTS_OBJ): $(VENDOR_DIR_OBJ)/tests/%.o: tests/%.c
	@mkdir -p $(VENDOR_DIR_OBJ)/tests
	@$(CC) $(CFLAGS) -O0 $< -c -o $@




simple: ## name tbd, Run test cases through C
simple: $(VENDOR_LIBTOMMATH_OBJ)
simple: $(VENDOR_DIR_OBJ)/proto_impl.o $(VENDOR_DIR_OBJ)/proto_derived.o $(VENDOR_DIR_OBJ)/proto_memory_check.o


simple: $(SIMPLE_TESTS_OBJ) $(DEMOLANG_OBJ) 
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean::
	@rm -f simple


MEMORY_TESTS := $(addprefix memory/test_,$(addsuffix .c,$(extract_files)))

memory/main.c:
	@echo "#include \"../vendor/EvilUnit/EvilUnit.h\"" > $@
	@echo "MAIN_MODULE()" >> $@
	@echo "{" >> $@
	@echo "  DEPENDS(tests_memchk_runner);" >> $@
	@echo "}" >> $@


$(MEMORY_TESTS):	memory/test_%.c: testcases/% memory/gen.awk extractfiles/files.mk
	gawk -f memory/gen.awk $< > $@

MEMORY_TESTS_SRC := $(MEMORY_TESTS) memory/runner.c memory/main.c
clean::
	rm -f $(MEMORY_TESTS) memory/main.c
MEMORY_TESTS_OBJ := $(MEMORY_TESTS_SRC:memory/%.c=$(VENDOR_DIR_OBJ)/memory/%.o)


$(MEMORY_TESTS_OBJ): $(VENDOR_DIR_OBJ)/memory/%.o: memory/%.c proto_memory_check.h
	@mkdir -p $(VENDOR_DIR_OBJ)/memory
	@$(CC) $(CFLAGS) -O0 $< -c -o $@

memory_test: ## name tbd, Run test cases through C
memory_test: $(VENDOR_LIBTOMMATH_OBJ)
memory_test: $(VENDOR_DIR_OBJ)/proto_impl.o $(VENDOR_DIR_OBJ)/proto_derived.o
memory_test: $(VENDOR_DIR_OBJ)/proto_memory_check.o

memory_test: $(MEMORY_TESTS_OBJ) $(DEMOLANG_OBJ) 
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean::
	@rm -f memory_test


run_tests: $(SIMPLE_PYTHON) simple memory_test
	python3 -m unittest discover python -v
	./simple
	./memory_test


calc:
calc: $(VENDOR_LIBTOMMATH_OBJ)
calc: $(VENDOR_DIR_OBJ)/proto_impl.o $(VENDOR_DIR_OBJ)/proto_derived.o $(VENDOR_DIR_OBJ)/proto_memory_check.o

# libfuzzer is a c++ thing
calc:	$(DEMOLANG_OBJ) 
	@$(CXX) -std=c++11 $^ $(LDFLAGS) -o $@

clean::
	@rm -rf $(DEMOLANG_DIR_OBJ)
	@rm -f calc


HELP_PADDING := 30
help:
	@sed -E \
	-e '/^([a-zA-Z_*.-]+::?[ ]*)##[ ]*([^#]*)$$/ !d # grep' \
	-e 's/([a-zA-Z_*.-]+:):?(.*)/  \1\2/ # drop :: and prefix pad' \
	-e ':again s/^([^#]{1,'$(HELP_PADDING)'})##[ ]*([^#]*)$$/\1 ##\2/ # insert a space' \
	-e 't again # do it again (termination is via {1, HELP_PADDING})' \
	-e 's/^([^#]*)##([^#]*)$$/\1\2/ # remove the ##' \
	$(MAKEFILE_LIST)

.EXTRA_PREREQS+=$(foreach mk, ${MAKEFILE_LIST},$(abspath ${mk}))
