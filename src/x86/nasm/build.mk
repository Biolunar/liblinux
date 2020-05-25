asmsrc = \
         src/$(ARCH)/$(TOOL)/_start.asm\
         src/$(ARCH)/$(TOOL)/exit.asm\
         src/$(ARCH)/$(TOOL)/exit_group.asm\
         src/$(ARCH)/$(TOOL)/rt_sigreturn.asm\
         src/$(ARCH)/$(TOOL)/set_gs.asm\
         src/$(ARCH)/$(TOOL)/sigreturn.asm\
         src/$(ARCH)/$(TOOL)/syscall0.asm\
         src/$(ARCH)/$(TOOL)/syscall1.asm\
         src/$(ARCH)/$(TOOL)/syscall2.asm\
         src/$(ARCH)/$(TOOL)/syscall3.asm\
         src/$(ARCH)/$(TOOL)/syscall4.asm\
         src/$(ARCH)/$(TOOL)/syscall5.asm\
         src/$(ARCH)/$(TOOL)/syscall6.asm\
         src/$(ARCH)/$(TOOL)/vfork.asm\
         src/$(ARCH)/$(TOOL)/vsyscall0.asm\
         src/$(ARCH)/$(TOOL)/vsyscall1.asm\
         src/$(ARCH)/$(TOOL)/vsyscall2.asm\
         src/$(ARCH)/$(TOOL)/vsyscall3.asm\
         src/$(ARCH)/$(TOOL)/vsyscall4.asm\
         src/$(ARCH)/$(TOOL)/vsyscall5.asm\
         src/$(ARCH)/$(TOOL)/vsyscall6.asm\
         src/$(ARCH)/$(TOOL)/vsyscall_ptr.asm

asmflags = -f elf32
