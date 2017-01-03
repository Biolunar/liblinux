BITS 64

GLOBAL linux_syscall3
linux_syscall3:
	mov rax, rcx ; arg4 -> #
	syscall
	ret
