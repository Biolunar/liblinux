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

AS       = nasm
ASFLAGS  = -w+all
AR       = ar
ARFLAGS  = rcs
TARGET   = liblinux_syscall.a

objects  = exit.o\
	   exit_group.o\
	   rt_sigreturn.o\
	   syscall0.o\
	   syscall1.o\
	   syscall2.o\
	   syscall3.o\
	   syscall4.o\
	   syscall5.o\
	   syscall6.o

all: $(TARGET)

$(TARGET): $(objects)
	$(AR) $(ARFLAGS) $@ $(objects)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASFLAGS) -o $@ -f elf64 $<

clean:
	rm -f *.o *.a
