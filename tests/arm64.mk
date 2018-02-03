ARCH    := arm64

AS      := as
CC      := cc
LD      := ld
AR      := ar

ASFLAGS :=
CFLAGS  := -std=c11 -pedantic-errors -Wall -Wextra -g -ffreestanding -fno-stack-protector -I../include
LDFLAGS := -nostdlib -static -L../build -llinux_syscall
