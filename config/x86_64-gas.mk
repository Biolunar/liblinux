# Architecture selection
# ======================

ARCH     = x86_64
TOOL     = gas
INTERP   =
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-x86_64.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = as
ASMFLAGS =
AR       = ar
ARFLAGS  = -rcU
CC       = gcc
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -m64 -O3 -DNDEBUG -fdata-sections -ffunction-sections -Wall -Wextra
