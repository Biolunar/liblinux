/*
 * Copyright 2018-2019 Mahdi Khanalizadeh
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

.section .text

.global _start
_start:
	/* mark the deepest stack frame */
	mov fp, #0
	mov lr, #0

	ldr r0, [sp] /* argc */
	add r1, sp, #4 /* argv */
	add r2, r1, r0, lsl #3 /* envp */

	b linux_start
