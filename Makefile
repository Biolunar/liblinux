#
# Copyright 2018-2021 Mahdi Khanalizadeh
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

.SUFFIXES:

###############################################################################
# Public variables

CONFIG = config.mk

###############################################################################
# Private variables

include $(CONFIG)
include src/$(ARCH)/build.mk

asmobj  = $(asmsrc:.asm=.o)
cobj    = $(csrc:.c=.o)
cdep    = $(csrc:.c=.d)
testdep = tests/error.d tests/compile.d $(tests:=.d)

###############################################################################
# Public targets

all: $(TARGET)

clean:
	rm -f $(TARGET) $(asmobj) $(cobj) $(cdep) tests/error tests/compile $(tests) $(testdep)

test: tests/error tests/compile $(tests)
	@$(INTERP) tests/error
	@tests/run_tests.sh $(ARCH) $(INTERP)

install: all
	mkdir -p $(DSTDIR)$(PREFIX)/include $(DSTDIR)$(PREFIX)/lib
	cp -r include/liblinux $(DSTDIR)$(PREFIX)/include
	cp $(TARGET) $(DSTDIR)$(PREFIX)/lib

uninstall:
	rm -rf $(DSTDIR)$(PREFIX)/include/liblinux
	rm -f $(DSTDIR)$(PREFIX)/lib/$(TARGET)

###############################################################################
# Private targets

-include $(cdep) $(testdep)

.SUFFIXES: .asm .o
.asm.o:
	$(ASM) $(ASMFLAGS) $(asmflags) -o $@ $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -nostdlib -ffreestanding -MMD -c -I include -o $@ $<

$(TARGET): $(asmobj) $(cobj)
	$(AR) $(ARFLAGS) $@ $(asmobj) $(cobj)

tests/error tests/compile $(tests): $(TARGET)

.SUFFIXES: .c
.c:
	$(CC) $(CFLAGS) -nostdlib -ffreestanding -fno-stack-protector -MMD -I include -static -o $@ $< $(TARGET)
