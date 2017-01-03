BITS 64

GLOBAL linux_exit_group
linux_exit_group:
	mov rax, 231
	syscall
