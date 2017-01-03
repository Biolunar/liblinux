BITS 64

GLOBAL linux_exit
linux_exit:
	mov rax, 60
	syscall
