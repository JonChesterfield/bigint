.SUFFIXES:
MAKEFLAGS += -r -j$(shell nproc)
.SECONDARY:
.SUFFIXES:

SHELL = sh -xv


ifeq ($(origin CC),default)
CC = clang
endif

CFLAGS ?= -std=c99 -Wall -O0 -g -gdwarf-4

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

VENDOR_LIBTOMMATH_OBJ := $(VENDOR_LIBTOMMATH_SRC:$(VENDOR_DIR)/%.c=$(VENDOR_DIR_OBJ)/%.o)
.vendor.O/libtommath.o: $(VENDOR_LIBTOMMATH_OBJ)
	ld -r $^ -o $@

build::	$(VENDOR_OBJ) .vendor.O/libtommath.o


$(VENDOR_DIR_OBJ)/proto_impl.o:	proto_impl.c proto.h $(VENDOR_HDR)
	@mkdir -p $(VENDOR_DIR_OBJ)
	@$(CC) $(CFLAGS) $< -c -o $@

$(VENDOR_DIR_OBJ)/proto.o:	proto.c proto.h $(VENDOR_HDR)
	@mkdir -p $(VENDOR_DIR_OBJ)
	@$(CC) $(CFLAGS) $< -c -o $@

proto:	$(VENDOR_DIR_OBJ)/proto.o $(VENDOR_DIR_OBJ)/proto_impl.o $(VENDOR_LIBTOMMATH_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
clean::
	@rm -f proto

build::	proto




DEMOLANG_DIR := demolang
DEMOLANG_DIR_OBJ := .$(DEMOLANG_DIR).O
include demolang/files.mk
DEMOLANG_SRC := $(addprefix demolang/,$(filter %.c,$(DEMOLANG_FILES)))
DEMOLANG_HDR := $(addprefix demolang/,$(filter %.h,$(DEMOLANG_FILES)))
DEMOLANG_OBJ := $(DEMOLANG_SRC:$(DEMOLANG_DIR)/%.c=$(DEMOLANG_DIR_OBJ)/%.o)

$(DEMOLANG_DIR_OBJ)/%.o:	$(DEMOLANG_DIR)/%.c $(DEMOLANG_HDR) proto.h $(VENDOR_HDR)
	@mkdir -p $(DEMOLANG_DIR_OBJ)
	@$(CC) $(CFLAGS) $< -c -o $@

demolang::	$(DEMOLANG_OBJ)

calc: ## Build a prefix notation calculator
calc: $(VENDOR_LIBTOMMATH_OBJ)
calc: $(VENDOR_DIR_OBJ)/proto_impl.o

calc:	$(DEMOLANG_OBJ) 
	@$(CC) $(CFLAGS) $^ -o $@

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
