BITS 64

GLOBAL linux_syscall5
linux_syscall5:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r9 ; arg6 -> #
	syscall
	ret
