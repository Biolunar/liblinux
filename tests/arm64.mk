ARCH    := arm64

AR      := ar
AS      := as
CC      := cc
LD      := ld

ARFLAGS :=
ASFLAGS :=
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
