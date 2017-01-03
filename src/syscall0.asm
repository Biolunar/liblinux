BITS 64

GLOBAL linux_syscall0
linux_syscall0:
	mov rax, rdi ; arg1 -> #
	syscall
	ret
