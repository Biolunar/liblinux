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

CONFIG  = config.mk

-include $(CONFIG)

makecmd = $(MAKE) ARCH=$(ARCH) TARGET=$(TARGET) AS=$(AS) AR=$(AR) CC=$(CC) LD=$(LD) ASFLAGS="$(ASFLAGS)" ARFLAGS="$(ARFLAGS)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)"

help:
	@echo "Usage: make [CONFIG=filename.mk] <command>"
	@echo "Valid commands:"
	@echo "    help      - this help message"
	@echo "    build     - builds the library"
	@echo "    test      - builds the library and runs the test suite"
	@echo "    clean     - removes all previously build files"
	@echo "    install   - copies the headers and all previously build libraries to (DESTDIR)(PREFIX)"
	@echo "    uninstall - removes the headers and all previously build libraries from (DESTDIR)(PREFIX)"
	@echo "You need to specfiy a config file to build or install the library or you can create a default config file named 'config.mk'."

build:
	@cd src/$(ARCH) && $(makecmd)
	mkdir -p build
	cp src/$(ARCH)/start/$(TARGET)_start.a src/$(ARCH)/syscall/$(TARGET)_syscall.a build

test: build
	@cd test && $(makecmd)

install:
	@echo "Installing library to $(DESTDIR)$(PREFIX)/include and $(DESTDIR)$(PREFIX)/lib/liblinux"
	mkdir -p $(DESTDIR)$(PREFIX)/include $(DESTDIR)$(PREFIX)/lib/liblinux
	cp -r include/liblinux $(DESTDIR)$(PREFIX)/include
	-cp -r build/*.a $(DESTDIR)$(PREFIX)/lib/liblinux

uninstall:
	@echo "Uninstalling library from $(DESTDIR)$(PREFIX)/include and $(DESTDIR)$(PREFIX)/lib"
	rm -rf $(DESTDIR)$(PREFIX)/include/liblinux
	rm -rf $(DESTDIR)$(PREFIX)/lib/liblinux

clean:
	rm -rf build
	@cd test       && $(makecmd) clean
	@cd src/x86    && $(makecmd) clean
	@cd src/x32    && $(makecmd) clean
	@cd src/x86_64 && $(makecmd) clean
	@cd src/arm64  && $(makecmd) clean
