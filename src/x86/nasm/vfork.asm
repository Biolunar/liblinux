;
; Copyright 2018-2021 Mahdi Khanalizadeh
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

BITS 32

; The parent process will be suspended while the child is running. The parent
; expects an unmodified stack, but since the child inevitably modifies the
; stack, we have to save the return address and the parameter in registers and
; restore them for the parent before returning.

GLOBAL linux_vfork
linux_vfork:
	mov ecx, [esp+0] ; Save the return address in a scratch register.
	mov edx, [esp+4] ; Save parameter in a scratch register.

	mov eax, 190
	int 0x80

	test eax, eax
	jz .child

	; Now we are inside the parent.

	mov [esp+4], edx ; Restore the parameter.
	mov [esp+0], ecx ; Restore the return address.

	; Test if an error occurred.
	mov edx, eax
	neg edx
	xor ecx, ecx
	cmp eax, 0xfffff000
	cmova ecx, edx
	test cx, cx ; Check if no error.
	jnz .out
	mov edx, [esp+4]
	test edx, edx ; Check if parameter was null.
	jz .out
	mov [edx], eax
.out:
	mov eax, ecx
	ret

.child:
	mov [edx], eax
	ret
