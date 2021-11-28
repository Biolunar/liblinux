# Architecture selection
# ======================

ARCH     = arm-eabi
TOOL     = gas
INTERP   = qemu-arm
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux-arm-eabi.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = arm-none-eabi-as
ASMFLAGS = -EL
AR       = arm-none-eabi-ar
ARFLAGS  = -rcU
CC       = arm-none-eabi-gcc
CFLAGS   = -std=c17 -pedantic-errors -fno-asm -fno-builtin -fno-stack-protector -O3 -DNDEBUG -fdata-sections -ffunction-sections -Wall -Wextra
