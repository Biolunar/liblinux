#
# Copyright 2018-2019 Mahdi Khanalizadeh
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
include $(CONFIG)

###############################################################################
# Private variables

include src/$(ARCH)/build.mk

asmobj = $(asmsrc:.asm=.o)
cobj   = $(csrc:.c=.o)

###############################################################################
# Public targets

all: $(TARGET)

clean:
	rm -f $(TARGET) $(asmobj) $(cobj) tests/start

test:
	@echo "Tests are not implemented yet!"

###############################################################################
# Private targets

.SUFFIXES: .asm .o
.asm.o:
	$(ASM) $(ASMFLAGS) $(asmflags) -o $@ $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c -I include/liblinux -o $@ $<
	
$(TARGET): $(asmobj) $(cobj)
	$(AR) $(ARFLAGS) $@ $(asmobj) $(cobj)
