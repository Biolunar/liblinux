ARCH    := x32

AR      := ar
AS      := nasm
CC      := cc
LD      := ld

ARFLAGS :=
ASFLAGS := -f elfx32
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
