#
# Copyright 2018 Mahdi Khanalizadeh
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

.POSIX:
.SUFFIXES:

DESTDIR  =
PREFIX   = /usr/local
TARGET   = liblinux

arch     = x86 x32 x86_64 arm64

help:
	@echo "Usage: make [option=value ...] <architecture/command>"
	@echo "Valid architectures:"
	@echo "    $(arch)"
	@echo "Valid commands:"
	@echo "    clean     - removes all previously build files"
	@echo "    install   - copies the headers and all previously build libraries from (DESTDIR)(PREFIX)"
	@echo "    uninstall - removes the headers and all previously build libraries from (DESTDIR)(PREFIX)"
	@echo "Valid architecture options:"
	@echo "    TARGET    - the name of the library (default: $(TARGET))"
	@echo "    AS        - name of the assembler program to use (default depends on the architecture)"
	@echo "    ASFLAGS   - additional flags passed to the assembler (default depends on the architecture)"
	@echo "    AR        - name of the archiver program to use (default depends on the architecture)"
	@echo "    ARFLAGS   - commands passed to the archiver (default depends on the architecture)"
	@echo "Valid command options:"
	@echo "    DESTDIR   - overrides the destination directory for the installation (default: $(DESTDIR))"
	@echo "    PREFIX    - the installation prefix (default: $(PREFIX))"

$(arch):
	@cd src/$@ && $(MAKE)
	mkdir -p build/liblinux_syscall
	cp src/$@/start/$(TARGET)_start.a src/$@/syscall/$(TARGET)_syscall.a build/liblinux_syscall

install:
	@echo "Installing library to $(DESTDIR)$(PREFIX)/include and $(DESTDIR)$(PREFIX)/lib"
	mkdir -p $(DESTDIR)$(PREFIX)/include $(DESTDIR)$(PREFIX)/lib
	cp -r include/* $(DESTDIR)$(PREFIX)/include
	-cp -r build/liblinux_syscall $(DESTDIR)$(PREFIX)/lib

uninstall:
	@echo "Uninstalling library from $(DESTDIR)$(PREFIX)/include and $(DESTDIR)$(PREFIX)/lib"
	rm -rf $(DESTDIR)$(PREFIX)/include/liblinux_syscall
	rm -rf $(DESTDIR)$(PREFIX)/lib/liblinux_syscall

clean:
	rm -rf build
	@cd src/x86/start      && $(MAKE) clean
	@cd src/x86/syscall    && $(MAKE) clean
	@cd src/x32/start      && $(MAKE) clean
	@cd src/x32/syscall    && $(MAKE) clean
	@cd src/x86_64/start   && $(MAKE) clean
	@cd src/x86_64/syscall && $(MAKE) clean
	@cd src/arm64/start    && $(MAKE) clean
	@cd src/arm64/syscall  && $(MAKE) clean
