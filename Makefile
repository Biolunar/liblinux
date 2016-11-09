PREFIX   := /usr/local

NAME     := liblinux_syscalls
TARGET   := $(NAME).a
BUILDDIR := build

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(BUILDDIR)/syscalls.o
	@ar rcs $(BUILDDIR)/$(TARGET) $(BUILDDIR)/syscalls.o

$(BUILDDIR)/syscalls.o: src/syscalls.asm
	@mkdir -p $(BUILDDIR)
	@nasm -f elf64 src/syscalls.asm -o $(BUILDDIR)/syscalls.o

install: all
	@echo Installing library to $(PREFIX)/include and $(PREFIX)/lib
	@mkdir -p $(PREFIX)/include/$(NAME) $(PREFIX)/lib
	@cp -r include/* $(PREFIX)/include/$(NAME)
	@cp $(BUILDDIR)/$(TARGET) $(PREFIX)/lib

uninstall:
	@echo Uninstalling library from $(PREFIX)/include and $(PREFIX)/lib
	@rm -rf $(PREFIX)/include/$(NAME)
	@rm -rf $(PREFIX)/lib/$(TARGET)

clean:
	@rm -rf $(BUILDDIR)

.PHONY: all install uninstall clean
