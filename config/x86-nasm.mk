# Architecture selection
# ======================

ARCH     = x86
TOOL     = nasm
INTERP   =
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-x86.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = nasm
ASMFLAGS = -w+all -Ox
AR       = ar
ARFLAGS  = -rcU
CC       = clang
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -m32 -O3 -DNDEBUG -fdata-sections -ffunction-sections -Weverything -Wno-c++98-compat -Wno-padded
