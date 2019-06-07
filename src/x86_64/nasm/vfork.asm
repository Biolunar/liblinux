;
; Copyright 2018-2019 Mahdi Khanalizadeh
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;

BITS 64

; The parent process will be suspended while the child is running. The parent
; expects an unmodified stack, but since the child inevitably modifies the
; stack (e.g. by returning from this function), we have to save the return
; address in a register and restore it for the parent before returning.

GLOBAL linux_vfork_raw
linux_vfork_raw:
	pop rdi ; save the return address in a scratch register
	mov rax, 58
	syscall
	push rdi ; restore the return address
	ret
