ARCH    := x86

AR      := ar
AS      := nasm
CC      := cc
LD      := ld

ARFLAGS :=
ASFLAGS := -f elf32
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
