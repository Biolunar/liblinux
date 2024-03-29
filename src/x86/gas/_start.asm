/*
 * Copyright 2018-2021 Mahdi Khanalizadeh
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

.global _start
_start:
	xor ebp, ebp # mark the deepest stack frame

	mov edi, [esp] # argc
	lea esi, [esp + 4] # argv
	lea edx, [4 * edi + esp + 8] # envp

	sub esp, 4 # This is needed to align the stack on a 16 byte boundary.

	push edx # envp
	push esi # argv
	push edi # argc

	# Use the call instruction so that the eip register gets pushed onto the stack
	# to correctly set up the stack frame for the C function.
	call linux_start

	# Issue an invalid instruction because linux_start is not allowed to return.
	ud2
