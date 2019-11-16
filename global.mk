# Global options, used in each Makefile in the project
# If you have to change a tool name, or to add an option
# for every part of the project, this is the good place.


cc		:= gcc
ar		:= $(cc)-ar
header		:= -Iinclude
cflags		:= -W -Wall -Wextra -fno-builtin -std=c11 -g
extra		:= -lcsfml-graphics -lcsfml-system -lcsfml-window \
       			-lcsfml-audio
EXEC		:= sprite_coder
BUILD-DIR	:= build
SRC-DIR		:= src

red	:= \033[1;31m
green	:= \033[1;32m
blue	:= \033[1;34m
white	:= \033[1;37m
nocolor	:= \033[1;0m

define n
# Force new line character

endef
