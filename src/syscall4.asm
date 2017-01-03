BITS 64

GLOBAL linux_syscall4
linux_syscall4:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r8 ; arg5 -> #
	syscall
	ret
