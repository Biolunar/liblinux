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

PREFIX   := /usr/local

LIBNAME  := liblinux_syscall
BUILDDIR := build
TARGET   := $(LIBNAME).a
ARCH     := x86 x32 x86_64 arm64

all:
	@echo "Choose an architecture as a build target:"
	@echo "$$ make <arch>"
	@echo "Following architectures are currently supported:"
	@echo "    $(ARCH)"

$(ARCH):
	@$(MAKE) --no-print-directory TARGET=../../$(BUILDDIR)/$(TARGET) BUILDDIR=../../$(BUILDDIR) -C src/$@

install: $(BUILDDIR)
	@echo Installing library to $(PREFIX)/include and $(PREFIX)/lib
	@mkdir -p $(PREFIX)/include $(PREFIX)/lib
	@cp -r include/$(LIBNAME) $(PREFIX)/include
	@cp $(BUILDDIR)/$(TARGET) $(PREFIX)/lib

uninstall:
	@echo Uninstalling library from $(PREFIX)/include and $(PREFIX)/lib
	@rm -rf $(PREFIX)/include/$(LIBNAME)
	@rm -rf $(PREFIX)/lib/$(TARGET)

clean:
	@rm -rf $(BUILDDIR)

.PHONY: all install uninstall clean $(ARCH)
