PREFIX   := /usr/local

NAME     := liblinux_syscall
TARGET   := $(NAME).a
BUILDDIR := build

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(BUILDDIR)/syscall.o
	@ar rcs $(BUILDDIR)/$(TARGET) $(BUILDDIR)/syscall.o

$(BUILDDIR)/syscall.o: src/syscall.asm
	@mkdir -p $(BUILDDIR)
	@nasm -f elf64 src/syscall.asm -o $(BUILDDIR)/syscall.o

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
