$(if $(FETCH_DIR),,$(error fetch.mk requires fetch dir))

# Localise all the pulling files from the internet during build here
# The ifeq/endif logic is a little obscure. The idea is that we don't especially want
# to download the files again if this makefile changes. The ifeq is parsed when reading
# this makefile which is approximately the start of the build. If the files were missing,
# go and get them. Otherwise assume whatever is already on disk is fine and leave it alone.

fetch::	$(FETCH_DIR)/EvilUnit/EvilUnit.h
ifeq (,$(wildcard $(FETCH_DIR)/EvilUnit/EvilUnit.h))
$(FETCH_DIR)/EvilUnit/EvilUnit.h:
	@rm -rf $(FETCH_DIR)/EvilUnit
	git clone https://github.com/JonChesterfield/EvilUnit.git $(FETCH_DIR)/EvilUnit
endif

fetch:: $(FETCH_DIR)/lua/lua.tar.gz
ifeq (,$(wildcard $(FETCH_DIR)/lua/lua.tar.gz))
$(FETCH_DIR)/lua/lua.tar.gz:
	@rm -rf $(FETCH_DIR)/lua
	@mkdir -p $(FETCH_DIR)/lua
	wget https://www.lua.org/ftp/lua-5.4.7.tar.gz -O $@

endif

