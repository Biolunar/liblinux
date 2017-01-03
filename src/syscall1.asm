BITS 64

GLOBAL linux_syscall1
linux_syscall1:
	mov rax, rsi ; arg2 -> #
	syscall
	ret
