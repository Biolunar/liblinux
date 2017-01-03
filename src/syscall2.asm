BITS 64

GLOBAL linux_syscall2
linux_syscall2:
	mov rax, rdx ; arg3 -> #
	syscall
	ret
