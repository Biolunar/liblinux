BITS 64

GLOBAL linux_syscall6
linux_syscall6:
	mov r10, rcx ; arg4 -> arg4
	mov rax, [rsp+8] ; arg7 -> #
	syscall
	ret
