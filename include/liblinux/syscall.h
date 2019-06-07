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

#ifndef HEADER_LIBLINUX_SYSCALL_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_H_INCLUDED

#include "version.h"
#include "arch.h"
#include "error.h"

#include <stdint.h>
#include <stdnoreturn.h>

/*
 * Architectures with 32 bit word sizes require you to split 64 bit arguments
 * into two 32 bit arguments.
 */
#if defined(LINUX_ARCH_ARM_EABI) || \
    defined(LINUX_ARCH_X86)
#define LINUX_EXPAND(x) \
        (union{uint64_t ll; uint32_t l[2];}){.ll = (uint64_t)(x)}.l[0], \
        (union{uint64_t ll; uint32_t l[2];}){.ll = (uint64_t)(x)}.l[1]
#endif

//==============================================================================
// Generic functions

/*
 * These are the syscall wrappers.
 * The number on each function specifies how many arguments the syscall takes.
 * The argument called "num" is the actual syscall number, which can be found
 * in the header names.h.
 */

linux_word_t linux_syscall0(linux_uword_t num);
linux_word_t linux_syscall1(linux_uword_t arg1, linux_uword_t num);
linux_word_t linux_syscall2(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t num);
linux_word_t linux_syscall3(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t num);
linux_word_t linux_syscall4(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t num);
linux_word_t linux_syscall5(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t num);
linux_word_t linux_syscall6(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t arg6, linux_uword_t num);

#ifdef LINUX_ARCH_X86

/*
 * On x86 you use the assembly instruction "int 0x80" to invoke syscalls,
 * which is not very fast. Therefore Linux exports a function called
 * "__kernel_vsyscall" in the vDSO for applications to use, to speed up the
 * the context switch.
 * To make use of this function, just assign to the address of the
 * __kernel_vsyscall symbol to the variable linux_vsyscall_ptr. Then you can
 * invoke syscalls with the linux_vsyscallX functions.
 */

extern void const* linux_vsyscall_ptr; // Set this to the __kernel_vsyscall symbol exported by the vDSO or the following functions will segfault.

linux_word_t linux_vsyscall0(linux_uword_t num);
linux_word_t linux_vsyscall1(linux_uword_t arg1, linux_uword_t num);
linux_word_t linux_vsyscall2(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t num);
linux_word_t linux_vsyscall3(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t num);
linux_word_t linux_vsyscall4(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t num);
linux_word_t linux_vsyscall5(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t num);
linux_word_t linux_vsyscall6(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t arg6, linux_uword_t num);

#endif // LINUX_ARCH_X86

// Generic functions
//==============================================================================

//==============================================================================
// Direct functions

/*
 * The exit functions are implemented in assembly because it is the most
 * efficient way to do so. Also we save a couple of bytes since they never
 * return and don't need to follow C's calling convention.
 */
noreturn void linux_exit(uint8_t status);
noreturn void linux_exit_group(uint8_t status);

/*
 * The following functions are intended to be used as the restorer callback in
 * the sigaction structure. These functions must be implemented in assembly
 * because they don't use the C calling convention.
 */
noreturn void linux_rt_sigreturn(void);
#if defined(LINUX_ARCH_ARM_EABI) || \
    defined(LINUX_ARCH_X86)
noreturn void linux_sigreturn(void);
#endif // LINUX_ARCH_ARM_EABI || LINUX_ARCH_X86

/*
 * vfork is a special syscall. Since parent and child share memory, the wrapper
 * function needs to fix the stack for the parent after the child finishes.
 * This is done in this function.
 */
#if defined(LINUX_ARCH_X86)    || \
    defined(LINUX_ARCH_X32)    || \
    defined(LINUX_ARCH_X86_64)
linux_word_t linux_vfork_raw(void);
#endif // LINUX_ARCH_X86 || LINUX_ARCH_X32 || LINUX_ARCH_X86_64

// Direct functions
//==============================================================================

#endif // !HEADER_LIBLINUX_SYSCALL_H_INCLUDED
