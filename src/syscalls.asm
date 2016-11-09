BITS 64
GLOBAL linux_syscall0
GLOBAL linux_syscall1
GLOBAL linux_syscall2
GLOBAL linux_syscall3
GLOBAL linux_syscall4
GLOBAL linux_syscall5
GLOBAL linux_syscall6

; TODO: improve argument order for maximum efficiency

linux_syscall0:
	mov rax, rdi
	syscall
	ret

linux_syscall1:
	mov rax, rdi
	mov rdi, rsi
	syscall
	ret

linux_syscall2:
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	syscall
	ret

linux_syscall3:
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	syscall
	ret

linux_syscall4:
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	mov r10, r8
	syscall
	ret

linux_syscall5:
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	mov r10, r8
	mov r8, r9
	syscall
	ret

linux_syscall6:
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	mov r10, r8
	mov r8, r9
	mov r9, [rsp+8]
	syscall
	ret
