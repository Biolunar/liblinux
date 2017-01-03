BITS 64

; C:
; return value: rax
; parameter: rdi, rsi, rdx, rcx, r8, r9, rest on stack in reversed order
; stack alignment: 16
; preserved: rbx, rsp, rbp, r12, r13, r14, r15
; scratch: rax, rdi, rsi, rdx, rcx, r8, r9, r10, r11

; Linux:
; syscall number: rax
; return value: rax
; parameter: rdi, rsi, rdx, r10, r8, r9

;-------------------------------------------------------------------------------
; Generic functions

GLOBAL linux_syscall0
linux_syscall0:
	mov rax, rdi ; arg1 -> #
	syscall
	ret

GLOBAL linux_syscall1
linux_syscall1:
	mov rax, rsi ; arg2 -> #
	syscall
	ret

GLOBAL linux_syscall2
linux_syscall2:
	mov rax, rdx ; arg3 -> #
	syscall
	ret

GLOBAL linux_syscall3
linux_syscall3:
	mov rax, rcx ; arg4 -> #
	syscall
	ret

GLOBAL linux_syscall4
linux_syscall4:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r8 ; arg5 -> #
	syscall
	ret

GLOBAL linux_syscall5
linux_syscall5:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r9 ; arg6 -> #
	syscall
	ret

GLOBAL linux_syscall6
linux_syscall6:
	mov r10, rcx ; arg4 -> arg4
	mov rax, [rsp+8] ; arg7 -> #
	syscall
	ret

; Generic functions
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; Direct functions

GLOBAL linux_exit
linux_exit:
	mov rax, 60
	syscall

GLOBAL linux_exit_group
linux_exit_group:
	mov rax, 231
	syscall

; Direct functions
;-------------------------------------------------------------------------------
