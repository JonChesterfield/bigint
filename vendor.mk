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
# leave doc alone, has a manual and a license in it
# also leave Makefile alone for now, might need to lift some defines from it
	for F in src; do rm -r $(VENDOR_DIR)/lua/$$F; done
	printf "VENDOR_LUA_FILES :=" > $@
	find $(VENDOR_DIR)/lua -type f -iname '*.[hc]' -printf ' \\\n  %p' >> $@
	echo "" >> $@
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

vendor:: $(VENDOR_DIR)/libtommath.mk
include $(VENDOR_DIR)/libtommath.mk

VENDOR_LIBTOMMATH_SRC := $(filter %.c,$(VENDOR_LIBTOMMATH_FILES))
VENDOR_LIBTOMMATH_HDR := $(filter %.h,$(VENDOR_LIBTOMMATH_FILES))

VENDOR_SRC := $(VENDOR_SRC) $(VENDOR_LIBTOMMATH_SRC)
VENDOR_HDR := $(VENDOR_HDR) $(VENDOR_LIBTOMMATH_HDR)

ifeq (,$(wildcard $(VENDOR_DIR)/libtommath.mk))

VENDOR_LIBTOM_REPLACEMENTS := bn_mp_init.c tommath_overrides.h bn_mp_mul.c
VENDOR_LIBTOM_DELETIONS := .github changes.txt helper.pl testme.sh bn_mp_fwrite.c bn_mp_prime_rand.c bn_mp_init_size.c bn_mp_grow.c bn_mp_shrink.c bn_mp_clear.c

$(VENDOR_DIR)/libtommath.mk: $(FETCH_DIR)/libtommath/libtommath.zip
	rm -rf $(VENDOR_DIR)/libtommath
	mkdir -p $(VENDOR_DIR)/libtommath
	unzip $< -d $(VENDOR_DIR)/libtommath
	for F in $(VENDOR_LIBTOM_DELETIONS) $(VENDOR_LIBTOM_REPLACEMENTS) ; do rm -rf $(VENDOR_DIR)/libtommath/libtommath-*/$$F; done

	mv $(VENDOR_DIR)/libtommath/libtommath-*/bn_*.c $(VENDOR_DIR)/libtommath
	mv $(VENDOR_DIR)/libtommath/libtommath-*/tommath*.h $(VENDOR_DIR)/libtommath

#	bn_s_mp_rand_platform has some references to functions which are only defined
#	on some platforms, but it also defines macros to say when they are defined
#	therefore can patch the call site to avoid the undef symbols
	sed -i -E \
	-e 's$$(.*HAS[(]S_READ_ARC4RANDOM[)].*)$$#ifdef BN_S_READ_ARC4RANDOM_C\n\1\n#endif$$g' \
	-e 's$$(.*HAS[(]S_READ_WINCSP[)].*)$$#ifdef BN_S_READ_WINCSP_C\n\1\n#endif$$g' \
	-e 's$$(.*HAS[(]S_READ_GETRANDOM[)].*)$$#ifdef BN_S_READ_GETRANDOM_C\n\1\n#endif$$g' \
	-e 's$$(.*HAS[(]S_READ_URANDOM[)].*)$$#ifdef BN_S_READ_URANDOM_C\n\1\n#endif$$g' \
	-e 's$$(.*HAS[(]S_READ_LTM_RNG[)].*)$$#ifdef BN_S_READ_LTM_RNG\n\1\n#endif$$g' \
	$(VENDOR_DIR)/libtommath/bn_s_mp_rand_platform.c

	sed -i -E 's$$(#include "tommath.h")$$#include "tommath_overrides.h"\n\1$$' $(VENDOR_DIR)/libtommath/tommath_private.h 

	sed -i -E 's$$return.*s_mp_prime_random_ex.*;$$(void)a;(void)t;(void)size;(void)flags;(void)cb;(void)dat;\n   return MP_ERR;$$' $(VENDOR_DIR)/libtommath/bn_deprecated.c 

	$(foreach R,$(VENDOR_LIBTOM_REPLACEMENTS),cp replacements/libtommath/${R} $(VENDOR_DIR)/libtommath/ ;)

	printf "VENDOR_LIBTOMMATH_FILES :=" > $@
	find $(VENDOR_DIR)/libtommath -maxdepth 1 -type f -iname '*.[hc]' -printf ' \\\n  %p' >> $@
	echo "" >> $@

endif
