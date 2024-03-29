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

BITS 64

GLOBAL linux_syscall6
linux_syscall6:
	mov r10, rcx ; arg4 -> arg4
	mov rax, [rsp+8] ; arg7 -> #
	syscall
	ret
