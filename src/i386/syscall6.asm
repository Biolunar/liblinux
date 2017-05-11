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

GLOBAL linux_syscall6
linux_syscall6:
	push ebp
	push ebx
	push edi
	push esi
	mov ebx, [esp+20] ; arg1 -> arg1
	mov ecx, [esp+24] ; arg2 -> arg2
	mov edx, [esp+28] ; arg3 -> arg3
	mov esi, [esp+32] ; arg4 -> arg4
	mov edi, [esp+36] ; arg5 -> arg5
	mov ebp, [esp+40] ; arg6 -> arg6
	mov eax, [esp+44] ; arg7 -> #
	int 0x80
	pop esi
	pop edi
	pop ebx
	pop ebp
	ret
