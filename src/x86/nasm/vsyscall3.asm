;
; Copyright 2018-2020 Mahdi Khanalizadeh
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

EXTERN linux_vsyscall_ptr

GLOBAL linux_vsyscall3
linux_vsyscall3:
	xchg ebx, [esp+4] ; arg1 -> arg1
	mov ecx, [esp+8] ; arg2 -> arg2
	mov edx, [esp+12] ; arg3 -> arg3
	mov eax, [esp+16] ; arg4 -> #
	call [linux_vsyscall_ptr]
	mov ebx, [esp+4]
	ret
