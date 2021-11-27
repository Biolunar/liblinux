# Architecture selection
# ======================

ARCH     = riscv64
TOOL     = gas
INTERP   = qemu-riscv64
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-riscv64.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = riscv64-elf-as
ASMFLAGS = -march=rv64imfd -mabi=lp64d
AR       = riscv64-elf-ar
ARFLAGS  = -rcU
CC       = riscv64-elf-gcc
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -O3 -DNDEBUG -fdata-sections -ffunction-sections -flto -Wall -Wextra
