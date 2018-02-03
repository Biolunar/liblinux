ARCH    := x32

AS      := nasm
CC      := cc
LD      := ld

ASFLAGS := -f elfx32
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
