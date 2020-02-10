/*
 * Copyright 2018-2020 Mahdi Khanalizadeh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

.intel_syntax noprefix

.global linux_syscall6
linux_syscall6:
	push ebp
	push edi
	push esi
	push ebx
	mov eax, [esp+44] # arg7 -> #
	mov ebp, [esp+40] # arg6 -> arg6
	mov edi, [esp+36] # arg5 -> arg5
	mov esi, [esp+32] # arg4 -> arg4
	mov edx, [esp+28] # arg3 -> arg3
	mov ecx, [esp+24] # arg2 -> arg2
	mov ebx, [esp+20] # arg1 -> arg1
	int 0x80
	pop ebx
	pop esi
	pop edi
	pop ebp
	ret
