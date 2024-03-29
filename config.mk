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
#
# The INTERP variable can be used for cross compilation to specify an emulator
# to run the test suite in.

ARCH     = $(shell uname -m)
TOOL     = gas
INTERP   =
include src/$(ARCH)/$(TOOL)/build.mk

# Output
# ======

TARGET   = liblinux.a
DESTDIR  =
PREFIX   = /usr/local

# Toolchain
# =========

ASM      = as
ASMFLAGS =
AR       = ar
ARFLAGS  = -rv
CC       = cc
CFLAGS   = -std=c11 -fno-stack-protector -O3 -DNDEBUG
