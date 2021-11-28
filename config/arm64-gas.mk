# Architecture selection
# ======================

ARCH     = arm64
TOOL     = gas
INTERP   = qemu-aarch64
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-arm64.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = aarch64-linux-gnu-as
ASMFLAGS = -EL -mabi=lp64
AR       = aarch64-linux-gnu-ar
ARFLAGS  = -rcU
CC       = aarch64-linux-gnu-gcc
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -O3 -DNDEBUG -fdata-sections -ffunction-sections -Wall -Wextra
