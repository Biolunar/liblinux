BITS 64

GLOBAL linux_syscall0
GLOBAL linux_syscall1
GLOBAL linux_syscall2
GLOBAL linux_syscall3
GLOBAL linux_syscall4
GLOBAL linux_syscall5
GLOBAL linux_syscall6

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

linux_syscall0:
	mov rax, rdi ; arg1 -> #
	syscall
	ret

linux_syscall1:
	mov rax, rsi ; arg2 -> #
	syscall
	ret

linux_syscall2:
	mov rax, rdx ; arg3 -> #
	syscall
	ret

linux_syscall3:
	mov rax, rcx ; arg4 -> #
	syscall
	ret

linux_syscall4:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r8 ; arg5 -> #
	syscall
	ret

linux_syscall5:
	mov r10, rcx ; arg4 -> arg4
	mov rax,  r9 ; arg6 -> #
	syscall
	ret

linux_syscall6:
	mov r10, rcx ; arg4 -> arg4
	mov rax, [rsp+8] ; arg7 -> #
	syscall
	ret

; Generic functions
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; Direct functions

; TODO: Add an own symbol for every syscall.

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
