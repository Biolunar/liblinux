ARCH    = arm64
TARGET  = liblinux
DESTDIR =
PREFIX  = /usr/local

AS      = as
AR      = ar
CC      = cc
LD      = ld

ASFLAGS =
ARFLAGS = rcs
CFLAGS  = -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector
LDFLAGS = -nostdlib -static
