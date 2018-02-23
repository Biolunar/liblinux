ARCH    = x86_64
TARGET  = liblinux
DESTDIR =
PREFIX  = /usr/local

AS      = nasm
AR      = ar
CC      = cc
LD      = ld

ASFLAGS = -f elf64
ARFLAGS = rcs
CFLAGS  = -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector
LDFLAGS = -nostdlib -static
