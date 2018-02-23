ARCH    = x86
TARGET  = liblinux
DESTDIR =
PREFIX  = /usr/local

AS      = nasm
AR      = ar
CC      = cc
LD      = ld

ASFLAGS = -f elf32
ARFLAGS = rcs
CFLAGS  = -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector
LDFLAGS = -nostdlib -static
