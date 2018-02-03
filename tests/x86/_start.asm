;
; Copyright 2017 Mahdi Khanalizadeh
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
EXTERN linux_main

GLOBAL _start
_start:
	xor ebp, ebp ; mark the deepest stack frame
	push edx ; fini

	; Need an additional +4 offset for every [esp] access because the fini pointer
	; was pushed onto the stack.
	mov edi, [esp + 4] ; argc
	lea esi, [esp + 8] ; argv
	lea edx, [4 * edi + esp + 12] ; envp

	push edx ; envp
	push esi ; argv
	push edi ; argc

	; Use the call instruction so that the eip register gets pushed onto the stack
	; to correctly set up the stack frame for the C function.
	call linux_main
