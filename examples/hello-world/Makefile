.POSIX:
.SUFFIXES:

TARGET = hello
CC     = cc
CFLAGS = -std=c11 -pedantic-errors -nostdlib -ffreestanding -fno-stack-protector -g -Wall -Wextra
LDLIBS = -llinux

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ main.c $(LDLIBS)
