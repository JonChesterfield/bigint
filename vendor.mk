$(if $(VENDOR_DIR),,$(error vendor.mk requires vendor dir))

# Each dependency adds {source,header} files to VENDOR_{SRC,HDR}
# The rebuild logic is handled by each one building a makefile fragment
# to indicate whether the files have been copied/edited as appropriate

vendor:: $(VENDOR_DIR)/lua.mk
include $(VENDOR_DIR)/lua.mk

VENDOR_LUA_SRC := $(filter %.c,$(VENDOR_LUA_FILES))
VENDOR_LUA_HDR := $(filter %.h,$(VENDOR_LUA_FILES))

VENDOR_SRC := $(VENDOR_SRC) $(VENDOR_LUA_SRC)
VENDOR_HDR := $(VENDOR_HDR) $(VENDOR_LUA_HDR)

ifeq (,$(wildcard $(VENDOR_DIR)/lua.mk))
$(VENDOR_DIR)/lua.mk: $(FETCH_DIR)/lua/lua.tar.gz
	@echo "Begin lua build"
	rm -rf $(VENDOR_DIR)/lua
	mkdir -p $(VENDOR_DIR)/lua
	tar xf $< -C $(VENDOR_DIR)/lua --strip-components=1
	mv $(VENDOR_DIR)/lua/src/* $(VENDOR_DIR)/lua/
	for F in doc Makefile README src; do rm -r $(VENDOR_DIR)/lua/$$F; done
	@echo "var"
	printf "VENDOR_LUA_FILES :=" > $(VENDOR_DIR)/lua.mk
	find $(VENDOR_DIR)/lua -type f -iname '*.[hc]' -printf ' \\\n  %p' >> $(VENDOR_DIR)/lua.mk
	echo "" >> $(VENDOR_DIR)/lua.mk
endif


vendor:: $(VENDOR_DIR)/EvilUnit.mk
include $(VENDOR_DIR)/EvilUnit.mk

ifeq (,$(wildcard $(VENDOR_DIR)/EvilUnit.mk))
$(VENDOR_DIR)/EvilUnit.mk: $(FETCH_DIR)/EvilUnit/EvilUnit.h
	rm -rf $(VENDOR_DIR)/EvilUnit
	mkdir -p $(VENDOR_DIR)/EvilUnit
	for F in EvilUnit.h EvilUnit_contract.h; do cp $(FETCH_DIR)/EvilUnit/$$F $(VENDOR_DIR)/EvilUnit/; done
	printf 'VENDOR_HDR := $$(VENDOR_HDR) $$(VENDOR_DIR)/EvilUnit/EvilUnit.h $$(VENDOR_DIR)/EvilUnit/EvilUnit_contract.h\n' > $@
endif
