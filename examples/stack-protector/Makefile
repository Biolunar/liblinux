.POSIX:
.SUFFIXES:

TARGET = hello
CC     = cc
CFLAGS = -std=c11 -pedantic-errors -g -Wall -Wextra
LDLIBS = -llinux

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -nostdlib -ffreestanding -static -fstack-protector-all -o $@ main.c $(LDLIBS)
