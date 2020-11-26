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

.section .text

.global _start
_start:
	lw a0, 0(sp) /* argc */
	addi a1, sp, 4 /* argv */

	/* envp */
	addi t0, a0, 1
	slli t0, t0, 2
	add a2, a1, t0

	/* Tail call sets the return address to 0, which will segfault if linux_start returns somehow. */
	tail linux_start
