#
# Copyright 2017 Mahdi Khanalizadeh
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

.global _start
_start:
	// mark the deepest stack frame
	mov x29, #0
	mov x30, #0

	ldr x0, [sp] // argc
	add x1, sp, #8 // argv

	// envp
	add x2, x1, x0, lsl #3
	add x2, x2, #16

	mov x3, #0 // fini
	bl linux_main
