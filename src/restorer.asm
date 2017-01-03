BITS 64

GLOBAL linux_restorer
linux_restorer:
	mov rax, 15
	syscall
