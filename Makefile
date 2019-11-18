#!/usr/bin/make -f
## ---
##	Project: sprite-coder
##	Author:
##		theo.cousinet@epitech.eu
##		yann.magnin@epitech.eu
## ---

##---
##	Static variables
##--
EXEC		:= sprite-coder

CC		:= gcc
CFLAGS		:= -Werror -Wall -W -Wextra -std=c18
EXTRA		:= -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio \
			-D _GNU_SOURCE -D _POSIX_C_SOURCE

HEADER		:= include
BUILD		:= build

red		:= \033[1;31m
green		:= \033[1;32m
blue		:= \033[1;34m
white		:= \033[1;37m
nocolor		:= \033[1;0m




##---
##	Automated variables
##---
SRC		:=
DIRECTORY	:= $(shell find src -not -path "*/\.*" -type d)
# Get all source files
$(foreach path,$(DIRECTORY),$(eval SRC	+= $(wildcard $(path)/*.c)))
# Geneate all object files
OBJ	:= $(patsubst %,$(BUILD)/%.o,$(subst /,_,$(subst src/,,$(basename $(SRC)))))




##---
##	General rules
##---
all: | $(BUILD) $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ) -I $(HEADER)

$(BUILD):
	@ printf "Create $(blue)$@$(nocolor) directory\n"
	@ mkdir -p $@

check:
	@ echo 'src: $(SRC)'
	@ echo 'obj: $(OBJ)'
	@ echo 'directory: $(DIRECTORY)'



##---
##	  Automated rules
##---
define rule-src
$(patsubst %,$(BUILD)/%.o,$(subst /,_,$(subst src/,,$(basename $1)))): $1
	@ printf "compiling $(white)$$<$(nocolor)..."
	@ $(CC) $(CFLAGS) -o $$@ -c $$< -I $(HEADER) $(EXTRA)
	@ printf "$(green)[ok]$(nocolor)\n"
endef

$(foreach source,$(SRC),$(eval		\
	$(call rule-src,$(source)))	\
)




##---
##	Cleaning rules
##---
clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(EXEC)

re: fclean all




.PHONY: re fclean clean all
