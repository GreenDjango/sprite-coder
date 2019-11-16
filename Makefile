##
## SPRITE CODER PROJECT, 2019
## Makefile, by fred (modifie by Yann)
## File description:
##	Need for build C-Project
## Little update: (Yann)
##	Each module (src/module/sub/*.c) are compiled
##	in "build/module/sub/*.o" path.
##	And global variable has moved to `glabal.mk`.
include global.mk


# Internal target files
TARGET-DIR	:= $(addprefix $(BUILD-DIR)/,$(SRC-DIR))
target-src	:= $(notdir $(wildcard $(SRC-DIR)/*.c))
target-obj	:= $(patsubst %.c,$(TARGET-DIR)/%.o,$(target-src))


#-------		--------#
#	Automated variables	#
#-------		--------#
MODULES		:=
$(foreach mod,$(MODULES),$(eval \
	target-$(mod)-src	:= $(notdir $(wildcard $(SRC-DIR)/$(mod)/*.c))					$n\
	target-$(mod)-obj	:= $$(patsubst %.c,$(TARGET-DIR)/$(mod)_%.o,$$(target-$(mod)-src)))		\
)
OBJ		:= $(target-obj) $(foreach mod,$(MODULES),$(target-$(mod)-obj))





#-------		--------#
#	Generic rules		#
#-------		--------#
#all: ;@echo $(OBJ) $(MODULES)
all: | $(TARGET-DIR) $(EXEC)

$(EXEC): $(OBJ)
	@ printf "$(green)/-------\n/  Link files\n/-------$(nocolor)\n"
	$(cc) $(cflags) -o $@ $^ $(extra)

$(TARGET-DIR): | $(BUILD-DIR)
	@ printf "Create $(blue)$@$(nocolor) directory\n"
	@ mkdir -p $@

$(BUILD-DIR):
	@ printf "Create $(blue)$@$(nocolor) directory\n"
	@ mkdir -p $@



#---			     ---#
#	  Automated rules	#
#---		    	     ---#
define rule-src
$(patsubst %.c,$(TARGET-DIR)/%.o,$1): $(SRC-DIR)/$1
	@ printf "compiling $(white)$(SRC-DIR)/$1$(nocolor)..."
	@ $(cc) $(cflags) -o $$@ -c $$< $(extra) $(header)
	@ printf "$(green)[ok]$(nocolor)\n"

endef

define rule-module
$(patsubst %.c,$(TARGET-DIR)/$2_%.o,$1): $(SRC-DIR)/$2/$1
	@ printf "compiling $(white)$(SRC-DIR)/$2/$1$(nocolor)..."
	@ $(cc) $(cflags) -o $$@ -c $$< $(extra) $(header)
	@ printf "$(green)[ok]$(nocolor)\n"
endef

$(foreach source,$(target-src), $(eval	\
	$(call rule-src,$(source)))	\
)

$(foreach mod,$(MODULES),				\
	$(foreach source,$(target-$(mod)-src), $(eval	\
		$(call rule-module,$(source),$(mod))))	\
)



#------  Clean and build  ------#
clean:
	@printf "$(red)Delete objects files$(nocolor)\n"
	rm -f $(OBJ)
	rm -rf $(TARGET-DIR)
	rm -rf $(BUILD-DIR)

fclean:	clean
	@printf "$(red)Delete all generated files$(nocolor)\n"
	rm -f $(EXEC)

re: fclean all

.PHONY: re fclean clean all check_all
