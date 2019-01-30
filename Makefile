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

###############################################################################
# Private variables

include $(CONFIG)
include src/$(ARCH)/build.mk

asmobj = $(asmsrc:.asm=.o)
cobj   = $(csrc:.c=.o)

###############################################################################
# Public targets

all: $(TARGET)

clean:
	rm -f $(TARGET) $(asmobj) $(cobj) tests/compile tests/compile.o tests/error tests/error.o tests/syscalls/sched_yield tests/syscalls/sched_yield.o tests/syscalls/getpid tests/syscalls/getpid.o

test: tests/compile tests/error tests/syscalls/sched_yield tests/syscalls/getpid
	tests/error
	tests/syscalls/sched_yield
	tests/syscalls/getpid

###############################################################################
# Private targets

.SUFFIXES: .asm .o
.asm.o:
	$(ASM) $(ASMFLAGS) $(asmflags) -o $@ $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c -I include -o $@ $<
	
$(TARGET): $(asmobj) $(cobj)
	$(AR) $(ARFLAGS) $@ $(asmobj) $(cobj)

tests/compile: $(TARGET) tests/compile.o
	$(CC) $(CFLAGS) -I include -o $@ tests/compile.o $(TARGET)

tests/error: $(TARGET) tests/error.o
	$(CC) $(CFLAGS) -I include -o $@ tests/error.o $(TARGET)

tests/syscalls/sched_yield: $(TARGET) tests/syscalls/sched_yield.o
	$(CC) $(CFLAGS) -I include -o $@ tests/syscalls/sched_yield.o $(TARGET)

tests/syscalls/getpid: $(TARGET) tests/syscalls/getpid.o
	$(CC) $(CFLAGS) -I include -o $@ tests/syscalls/getpid.o $(TARGET)
