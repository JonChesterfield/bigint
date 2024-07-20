.SUFFIXES:
MAKEFLAGS += -r -j$(shell nproc)
.SECONDARY:
.SUFFIXES:

SHELL = sh -xv


ifeq ($(origin CC),default)
CC = clang
endif

CFLAGS ?= -std=c99 -Wall

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
clean::
	@rm -rf $(VENDOR_DIR)
	@rm -rf $(VENDOR_DIR_OBJ)


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
