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

TARGET   = test
BUILDDIR = build
SOURCES  = $(wildcard *.c)

include $(CONFIG)

ifdef ARCH
BUILDDIR := $(BUILDDIR)/$(ARCH)
TARGET   := $(BUILDDIR)/$(TARGET)
SOURCES  := $(SOURCES) $(wildcard $(ARCH)/*.c)
endif

OBJECTS  = $(patsubst %.c, $(BUILDDIR)/%.o, $(SOURCES))
DEPS     = $(patsubst %.c, $(BUILDDIR)/%.dep, $(SOURCES))

ifdef CONFIG
all: $(TARGET)
else
all:
	@echo "To build the test suite, specify which config file to use."
	@echo "For example run: make CONFIG=x86.mk"
	@echo "to use the default settings for an x86 build."
endif

$(BUILDDIR):
	@mkdir -p $@/$(ARCH)

$(TARGET): $(OBJECTS) $(BUILDDIR)/$(ARCH)/_start.o $(DEPS)
	@$(LD) $(OBJECTS) $(BUILDDIR)/$(ARCH)/_start.o -o $@ $(LDFLAGS)

ifneq ($(MAKECMDGOALS), clean)
include $(DEPS)
endif

$(OBJECTS): $(BUILDDIR)/%.o: %.c $(BUILDDIR)/%.dep | $(BUILDDIR)
	@$(CC) -c $< -o $@ $(CFLAGS)

$(BUILDDIR)/$(ARCH)/_start.o: $(ARCH)/_start.asm
	@$(AS) $< -o $@ $(ASFLAGS)

$(DEPS): $(BUILDDIR)/%.dep: %.c | $(BUILDDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MM $< -MT $@ -MT $(<:.c=.o) -o $@

clean:
	@$(RM) -rf $(BUILDDIR)

.PHONY: all clean
