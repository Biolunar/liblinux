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

GLOBAL linux_syscall4
linux_syscall4:
	push ebx
	push esi
	mov ebx, [esp+12] ; arg1 -> arg1
	mov ecx, [esp+16] ; arg2 -> arg2
	mov edx, [esp+20] ; arg3 -> arg3
	mov esi, [esp+24] ; arg4 -> arg4
	mov eax, [esp+28] ; arg5 -> #
	int 0x80
	pop esi
	pop ebx
	ret
