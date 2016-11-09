TARGET := liblinux_syscalls.a

all: $(TARGET)

$(TARGET): syscalls.o
	@ar rcs $(TARGET) syscalls.o

syscalls.o: syscalls.asm
	@nasm -f elf64 syscalls.asm

clean:
	@rm -rf $(TARGET) *.o

.PHONY: all clean
