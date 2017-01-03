PREFIX   := /usr/local

NAME     := linux_syscall
LIBNAME  := lib$(NAME)
TARGET   := $(LIBNAME).a
BUILDDIR := build
SOURCES  := $(sort $(wildcard src/*.asm))
OBJECTS  := $(patsubst src/%.asm, $(BUILDDIR)/%.o, $(SOURCES))

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJECTS)
	@ar rcs $@ $^

$(OBJECTS): $(BUILDDIR)/%.o: src/%.asm | $(BUILDDIR)
	@nasm -f elf64 $< -o $@

$(BUILDDIR):
	@mkdir $@

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
