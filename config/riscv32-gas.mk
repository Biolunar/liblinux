# Architecture selection
# ======================

ARCH     = riscv32
TOOL     = gas
INTERP   = qemu-riscv32
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-riscv32.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = riscv32-elf-as
ASMFLAGS = -march=rv32imfd -mabi=ilp32d
AR       = riscv32-elf-ar
ARFLAGS  = -rcU
CC       = riscv64-elf-gcc
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -march=rv32imfd -mabi=ilp32d -O3 -DNDEBUG -fdata-sections -ffunction-sections -Wall -Wextra
