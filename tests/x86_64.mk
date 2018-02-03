ARCH    := x86_64

AS      := nasm
CC      := cc
LD      := ld
AR      := ar

ASFLAGS := -f elf64
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
