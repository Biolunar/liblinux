#
# Copyright 2017 Mahdi Khanalizadeh
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

TARGET   := test
WARNINGS := -Wall -Wextra
CFLAGS   := -std=c11 -pedantic-errors $(WARNINGS) -g -ffreestanding -fno-stack-protector -I../../include -m64
LDFLAGS  := -nostdlib -static -L../../build -llinux_syscall -m elf_x86_64

all: $(TARGET)

$(TARGET): main.o strlen.o memset.o memcpy.o _start.o
	@$(LD) $^ -o $@ $(LDFLAGS)

main.o: main.c x86_64.h ../strlen.h ../memset.h ../memcpy.h
	@$(CC) $(CFLAGS) $< -c

strlen.o: ../strlen.c ../strlen.h
	@$(CC) $(CFLAGS) $< -c

memset.o: ../memset.c ../memset.h
	@$(CC) $(CFLAGS) $< -c

memcpy.o: ../memcpy.c ../memcpy.h
	@$(CC) $(CFLAGS) $< -c

_start.o: _start.asm
	@nasm -f elf64 $<

clean:
	@$(RM) -f *.o $(TARGET)

.PHONY: all clean
