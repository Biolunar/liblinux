###############################################################################
# Public variables

ASM      = nasm
ASMFLAGS = -w+all -Ox

###############################################################################
# Private variables

asmsrc = \
         src/$(ARCH)/$(TOOL)/_start.asm\
         src/$(ARCH)/$(TOOL)/exit.asm\
         src/$(ARCH)/$(TOOL)/exit_group.asm\
         src/$(ARCH)/$(TOOL)/rt_sigreturn.asm\
         src/$(ARCH)/$(TOOL)/syscall0.asm\
         src/$(ARCH)/$(TOOL)/syscall1.asm\
         src/$(ARCH)/$(TOOL)/syscall2.asm\
         src/$(ARCH)/$(TOOL)/syscall3.asm\
         src/$(ARCH)/$(TOOL)/syscall4.asm\
         src/$(ARCH)/$(TOOL)/syscall5.asm\
         src/$(ARCH)/$(TOOL)/syscall6.asm\

asmflags = -f elf64
