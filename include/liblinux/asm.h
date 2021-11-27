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

#ifndef HEADER_LIBLINUX_ASM_H_INCLUDED
#define HEADER_LIBLINUX_ASM_H_INCLUDED

#include "version.h"
#include "endian.h"
#include "arch.h"
#include "error.h"
#include "types.h" // linux_pid_t

#include <stdint.h>
#include <stdnoreturn.h>

//==============================================================================
// Parameter expansion

/*
 * Architectures with 32 bit word sizes require you to split 64 bit arguments
 * into two 32 bit arguments.
 */

#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_RISCV32) || defined(LINUX_ARCH_X86)

#if defined(LINUX_ENDIAN_LITTLE)
#define LINUX_EXPAND(x) ((uint64_t)(x) & UINT32_MAX), ((uint64_t)(x) >> 32)
#else
#define LINUX_EXPAND(x) ((uint64_t)(x) >> 32), ((uint64_t)(x) & UINT32_MAX)
#endif

#endif // 32 bit architectures

//==============================================================================
// Syscalls

/*
 * The number on each function specifies how many arguments the syscall takes.
 * The argument called "number" is the actual syscall number, which can be
 * found in the header unistd.h.
 */

//------------------------------------------------------------------------------
// Generic

linux_word_t linux_syscall0(linux_uword_t number);
linux_word_t linux_syscall1(linux_uword_t arg1, linux_uword_t number);
linux_word_t linux_syscall2(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t number);
linux_word_t linux_syscall3(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t number);
linux_word_t linux_syscall4(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t number);
linux_word_t linux_syscall5(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t number);
linux_word_t linux_syscall6(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t arg6, linux_uword_t number);

//------------------------------------------------------------------------------
// VSyscalls

#ifdef LINUX_ARCH_X86

/*
 * On x86, you use the assembly instruction "int 0x80" to invoke syscalls,
 * which is not very fast. Therefore Linux exports a function called
 * __kernel_vsyscall in the vDSO for applications to use, to speed up the the
 * context switch.
 * To make use of this function, just assign to the address of the
 * __kernel_vsyscall symbol to the variable linux_vsyscall_ptr. Then you can
 * invoke syscalls with the linux_syscallX_v functions.
 */

extern void const* linux_vsyscall_ptr;

linux_word_t linux_syscall0_v(linux_uword_t number);
linux_word_t linux_syscall1_v(linux_uword_t arg1, linux_uword_t number);
linux_word_t linux_syscall2_v(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t number);
linux_word_t linux_syscall3_v(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t number);
linux_word_t linux_syscall4_v(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t number);
linux_word_t linux_syscall5_v(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t number);
linux_word_t linux_syscall6_v(linux_uword_t arg1, linux_uword_t arg2, linux_uword_t arg3, linux_uword_t arg4, linux_uword_t arg5, linux_uword_t arg6, linux_uword_t number);

#endif // LINUX_ARCH_X86

//==============================================================================
// Direct functions

/*
 * These functions must be implemented in assembly because they don't follow
 * C's normal calling convention.
 */

//------------------------------------------------------------------------------
// exit

/*
 * These functions are implemented in assembly because we save a couple of
 * bytes since they never return.
 */
noreturn void linux_exit(uint8_t status);
noreturn void linux_exit_group(uint8_t status);

//------------------------------------------------------------------------------
// sigreturn

/*
 * These functions are intended to be used as the restorer callback in
 * the sigaction structure. These functions must be implemented in assembly
 * because they don't use the C calling convention.
 */
// TODO: What's the purpose on architectures without a restorer?
noreturn void linux_rt_sigreturn(void);
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
noreturn void linux_sigreturn(void);
#endif // LINUX_ARCH_ARM_EABI || LINUX_ARCH_X86

//------------------------------------------------------------------------------
// clone

/*
 * vfork is a special syscall. Since parent and child share memory, the wrapper
 * function needs to fix the stack for the parent after the child finishes.
 */
#if defined(LINUX_ARCH_X86) || defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
linux_error_t linux_vfork(linux_pid_t* result);
#endif // LINUX_ARCH_X86 || LINUX_ARCH_X32 || LINUX_ARCH_X86_64

// TODO: Find a similar solution for clone.

//==============================================================================
// Entry point

/*
 * If you are not using the libc you can implement this function as the entry
 * point for your application.
 */
noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[]);

//==============================================================================
// Util

#if defined(LINUX_ARCH_X86)
/*
 * linux_set_gs is used to set the gs register. Useful after the
 * linux_set_thread_area syscall. You can easily do that by yourself but you
 * have to use assembly, so here's a convenience function.
 */
void linux_set_gs(uintptr_t value);
#endif

#endif // !HEADER_LIBLINUX_ASM_H_INCLUDED
