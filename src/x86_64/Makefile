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

TARGET   = liblinux
AS       = nasm
ASFLAGS  = -w+all
AR       = ar
ARFLAGS  = rcs

makecmd  = $(MAKE) TARGET=$(TARGET) AS=$(AS) ASFLAGS=$(ASFLAGS) AR=$(AR) ARFLAGS=$(ARFLAGS)

all:
	@cd start   && $(makecmd)
	@cd syscall && $(makecmd)

clean:
	@cd start   && $(makecmd) clean
	@cd syscall && $(makecmd) clean
