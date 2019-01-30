# Architecture selection
# ======================
#
# Allowed values:
# ARCH = [arm-eabi, arm64, x86, x32, x86_64]
#
# arm-eabi
# --------
# TOOL = [gas]
#
# arm64
# -----
# TOOL = [gas]
#
# x86
# -----
# TOOL = [gas, nasm]
#
# x32
# -----
# TOOL = [gas, nasm]
#
# x86_64
# -----
# TOOL = [gas, nasm]

ARCH     = $(shell uname -m)
TOOL     = gas

# Output
# ======

TARGET   = liblinux.a

# Toolchain
# =========

include src/$(ARCH)/$(TOOL)/build.mk # Sets following variables: ASM, ASMFLAGS
#ASM      = # Overwrite value here
#ASMFLAGS = # Overwrite value here
AR       = ar
ARFLAGS  = rc
CC       = cc
CFLAGS   = -std=c11 -pedantic-errors -nostdlib -ffreestanding -static -fno-stack-protector -Wno-pointer-to-int-cast
