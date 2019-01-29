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
 * Macro to avoid sign-extension.
 */
#define LINUX_PARAM(x) _Generic((x), _Bool:              (linux_word_t)(x),\
                                     char:               (linux_word_t)(unsigned char)(x),\
                                     signed char:        (linux_word_t)(unsigned char)(x),\
                                     unsigned char:      (linux_word_t)(x),\
                                     short:              (linux_word_t)(unsigned short)(x),\
                                     unsigned short:     (linux_word_t)(x),\
                                     int:                (linux_word_t)(unsigned int)(x),\
                                     unsigned int:       (linux_word_t)(x),\
                                     long:               (linux_word_t)(unsigned long)(x),\
                                     unsigned long:      (linux_word_t)(x),\
                                     long long:          (linux_word_t)(unsigned long long)(x),\
                                     unsigned long long: (linux_word_t)(x),\
				     default:            (linux_word_t)(uintptr_t)(x))

/*
 * Architectures with 32 bit word sizes require you to split 64 bit arguments
 * into two 32 bit arguments.
 */
#if defined(LINUX_ARCH_ARM_EABI) || \
    defined(LINUX_ARCH_X86)
#define LINUX_EXPAND(x) \
        LINUX_PARAM((union{int64_t ll; int32_t l[2];}){.ll = (int64_t)(x)}.l[0]), \
        LINUX_PARAM((union{int64_t ll; int32_t l[2];}){.ll = (int64_t)(x)}.l[1])
#endif

//------------------------------------------------------------------------------
// Generic functions

/*
 * These are the syscall wrappers.
 * The number on each function specifies how many arguments the syscall takes.
 * The argument called "num" is the actual syscall number, which can be found
 * in the header names.h.
 */

linux_word_t linux_syscall0(linux_word_t num);
linux_word_t linux_syscall1(linux_word_t arg1, linux_word_t num);
linux_word_t linux_syscall2(linux_word_t arg1, linux_word_t arg2, linux_word_t num);
linux_word_t linux_syscall3(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t num);
linux_word_t linux_syscall4(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t num);
linux_word_t linux_syscall5(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t arg5, linux_word_t num);
linux_word_t linux_syscall6(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t arg5, linux_word_t arg6, linux_word_t num);

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

linux_word_t linux_vsyscall0(linux_word_t num);
linux_word_t linux_vsyscall1(linux_word_t arg1, linux_word_t num);
linux_word_t linux_vsyscall2(linux_word_t arg1, linux_word_t arg2, linux_word_t num);
linux_word_t linux_vsyscall3(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t num);
linux_word_t linux_vsyscall4(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t num);
linux_word_t linux_vsyscall5(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t arg5, linux_word_t num);
linux_word_t linux_vsyscall6(linux_word_t arg1, linux_word_t arg2, linux_word_t arg3, linux_word_t arg4, linux_word_t arg5, linux_word_t arg6, linux_word_t num);

#endif // LINUX_ARCH_X86

// Generic functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
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

// Direct functions
//------------------------------------------------------------------------------

/*
 * Following macros are to convieniently declare and/or define the syscalls as
 * C functions.
 *
 * There are four sets of macros:
 * 1) functions with return value
 *   a) declaration only
 *   b) definition
 * 2) functions without return value
 *   a) declaration only
 *   b) definition
 *
 * LINUX_DECLARE_SYSCALL2_RET(NAME, arg1_t, arg1, arg2_t, arg2)
 * expands to
 * enum linux_error_t linux_NAME(arg1_t arg1, arg2_t arg2);
 *
 * LINUX_DECLARE_SYSCALL2_NORET(NAME, arg1_t, arg1, arg2_t, arg2, ret_t)
 * expands to
 * enum linux_error_t linux_NAME(arg1_t arg1, arg2_t arg2, ret_t*);
 * Notice that the last parameter is a pointer to the return type.
 *
 * Example:
 * The open syscall can be declared as
 * LINUX_DECLARE_SYSCALL3_RET(open, char const*, filename, int, flags, umode_t, mode, int);
 * which expands to the declaration
 * enum linux_error_t linux_open(char const* filename, int flags, umode_t mode, int* result);
 *
 * Functions which return a value created with these macros, accept a null
 * pointer as the final argument if the caller is not interested in the return
 * value.
 */

//------------------------------------------------------------------------------
// Declaration with return value

#define LINUX_DECLARE_SYSCALL0_RET(name, ret_t) \
	enum linux_error_t linux_ ## name(ret_t* result)
#define LINUX_DECLARE_SYSCALL1_RET(name, arg1_t, arg1, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, ret_t* result)
#define LINUX_DECLARE_SYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, ret_t* result)
#define LINUX_DECLARE_SYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, ret_t* result)
#define LINUX_DECLARE_SYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, ret_t* result)
#define LINUX_DECLARE_SYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, ret_t* result)
#define LINUX_DECLARE_SYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, arg6_t arg6, ret_t* result)

#ifdef LINUX_ARCH_X86

#define LINUX_DECLARE_VSYSCALL0_RET(name, ret_t) \
	enum linux_error_t linux_ ## name ## _v(ret_t* result)
#define LINUX_DECLARE_VSYSCALL1_RET(name, arg1_t, arg1, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, ret_t* result)
#define LINUX_DECLARE_VSYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, ret_t* result)
#define LINUX_DECLARE_VSYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, ret_t* result)
#define LINUX_DECLARE_VSYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, ret_t* result)
#define LINUX_DECLARE_VSYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, ret_t* result)
#define LINUX_DECLARE_VSYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, arg6_t arg6, ret_t* result)

#endif // LINUX_ARCH_X86

// Declaration with return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Declaration without return value

#define LINUX_DECLARE_SYSCALL0_NORET(name) \
	enum linux_error_t linux_ ## name(void)
#define LINUX_DECLARE_SYSCALL1_NORET(name, arg1_t, arg1) \
	enum linux_error_t linux_ ## name(arg1_t arg1)
#define LINUX_DECLARE_SYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2)
#define LINUX_DECLARE_SYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3)
#define LINUX_DECLARE_SYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4)
#define LINUX_DECLARE_SYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5)
#define LINUX_DECLARE_SYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6) \
	enum linux_error_t linux_ ## name(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, arg6_t arg6)

#ifdef LINUX_ARCH_X86

#define LINUX_DECLARE_VSYSCALL0_NORET(name) \
	enum linux_error_t linux_ ## name ## _v(void)
#define LINUX_DECLARE_VSYSCALL1_NORET(name, arg1_t, arg1) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1)
#define LINUX_DECLARE_VSYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2)
#define LINUX_DECLARE_VSYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3)
#define LINUX_DECLARE_VSYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4)
#define LINUX_DECLARE_VSYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5)
#define LINUX_DECLARE_VSYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6) \
	enum linux_error_t linux_ ## name ## _v(arg1_t arg1, arg2_t arg2, arg3_t arg3, arg4_t arg4, arg5_t arg5, arg6_t arg6)

#endif // LINUX_ARCH_X86

// Declaration without return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definition with return value

#define LINUX_DEFINE_SYSCALL0_RET(name, ret_t)                                        \
	enum linux_error_t linux_ ## name(ret_t* const result)                        \
	{                                                                             \
		linux_word_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                \
			return (enum linux_error_t)-ret;                              \
		if (result)                                                           \
			*result = (ret_t)ret;                                         \
		return linux_error_none;                                              \
	}
#define LINUX_DEFINE_SYSCALL1_RET(name, arg1_t, arg1, ret_t)                                             \
	enum linux_error_t linux_ ## name(arg1_t const arg1, ret_t* const result)                        \
	{                                                                                                \
		linux_word_t const ret = linux_syscall1(LINUX_PARAM(arg1), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                   \
			return (enum linux_error_t)-ret;                                                 \
		if (result)                                                                              \
			*result = (ret_t)ret;                                                            \
		return linux_error_none;                                                                 \
	}
#define LINUX_DEFINE_SYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t)                                                  \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, ret_t* const result)                        \
	{                                                                                                                   \
		linux_word_t const ret = linux_syscall2(LINUX_PARAM(arg1), LINUX_PARAM(arg2), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                      \
			return (enum linux_error_t)-ret;                                                                    \
		if (result)                                                                                                 \
			*result = (ret_t)ret;                                                                               \
		return linux_error_none;                                                                                    \
	}
#define LINUX_DEFINE_SYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t)                                                       \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result)                        \
	{                                                                                                                                      \
		linux_word_t const ret = linux_syscall3(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                         \
			return (enum linux_error_t)-ret;                                                                                       \
		if (result)                                                                                                                    \
			*result = (ret_t)ret;                                                                                                  \
		return linux_error_none;                                                                                                       \
	}
#define LINUX_DEFINE_SYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t)                                                            \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result)                        \
	{                                                                                                                                                         \
		linux_word_t const ret = linux_syscall4(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                          \
		if (result)                                                                                                                                       \
			*result = (ret_t)ret;                                                                                                                     \
		return linux_error_none;                                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t)                                                                 \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result)                        \
	{                                                                                                                                                                            \
		linux_word_t const ret = linux_syscall5(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                               \
			return (enum linux_error_t)-ret;                                                                                                                             \
		if (result)                                                                                                                                                          \
			*result = (ret_t)ret;                                                                                                                                        \
		return linux_error_none;                                                                                                                                             \
	}
#define LINUX_DEFINE_SYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t)                                                                      \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result)                        \
	{                                                                                                                                                                                               \
		linux_word_t const ret = linux_syscall6(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), LINUX_PARAM(arg6), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                                  \
			return (enum linux_error_t)-ret;                                                                                                                                                \
		if (result)                                                                                                                                                                             \
			*result = (ret_t)ret;                                                                                                                                                           \
		return linux_error_none;                                                                                                                                                                \
	}

#ifdef LINUX_ARCH_X86

#define LINUX_DEFINE_VSYSCALL0_RET(name, ret_t)                                        \
	enum linux_error_t linux_ ## name ## _v(ret_t* const result)                   \
	{                                                                              \
		linux_word_t const ret = linux_vsyscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                 \
			return (enum linux_error_t)-ret;                               \
		if (result)                                                            \
			*result = (ret_t)ret;                                          \
		return linux_error_none;                                               \
	}
#define LINUX_DEFINE_VSYSCALL1_RET(name, arg1_t, arg1, ret_t)                                             \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, ret_t* const result)                   \
	{                                                                                                 \
		linux_word_t const ret = linux_vsyscall1(LINUX_PARAM(arg1), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                    \
			return (enum linux_error_t)-ret;                                                  \
		if (result)                                                                               \
			*result = (ret_t)ret;                                                             \
		return linux_error_none;                                                                  \
	}
#define LINUX_DEFINE_VSYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t)                                                  \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, ret_t* const result)                   \
	{                                                                                                                    \
		linux_word_t const ret = linux_vsyscall2(LINUX_PARAM(arg1), LINUX_PARAM(arg2), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                       \
			return (enum linux_error_t)-ret;                                                                     \
		if (result)                                                                                                  \
			*result = (ret_t)ret;                                                                                \
		return linux_error_none;                                                                                     \
	}
#define LINUX_DEFINE_VSYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t)                                                       \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result)                   \
	{                                                                                                                                       \
		linux_word_t const ret = linux_vsyscall3(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                          \
			return (enum linux_error_t)-ret;                                                                                        \
		if (result)                                                                                                                     \
			*result = (ret_t)ret;                                                                                                   \
		return linux_error_none;                                                                                                        \
	}
#define LINUX_DEFINE_VSYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t)                                                            \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result)                   \
	{                                                                                                                                                          \
		linux_word_t const ret = linux_vsyscall4(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                           \
		if (result)                                                                                                                                        \
			*result = (ret_t)ret;                                                                                                                      \
		return linux_error_none;                                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t)                                                                  \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result)                    \
	{                                                                                                                                                                              \
		linux_word_t const ret = linux_vsyscall5(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), linux_syscall_name_ ## name);  \
		if (linux_syscall_returned_error(ret))                                                                                                                                 \
			return (enum linux_error_t)-ret;                                                                                                                               \
		if (result)                                                                                                                                                            \
			*result = (ret_t)ret;                                                                                                                                          \
		return linux_error_none;                                                                                                                                               \
	}
#define LINUX_DEFINE_VSYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t)                                                                      \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result)                   \
	{                                                                                                                                                                                                \
		linux_word_t const ret = linux_vsyscall6(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), LINUX_PARAM(arg6), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                                   \
			return (enum linux_error_t)-ret;                                                                                                                                                 \
		if (result)                                                                                                                                                                              \
			*result = (ret_t)ret;                                                                                                                                                            \
		return linux_error_none;                                                                                                                                                                 \
	}

#endif // LINUX_ARCH_X86

// Definition with return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definition without return value

#define LINUX_DEFINE_SYSCALL0_NORET(name)                                             \
	enum linux_error_t linux_ ## name(void)                                       \
	{                                                                             \
		linux_word_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                \
			return (enum linux_error_t)-ret;                              \
		return linux_error_none;                                              \
	}
#define LINUX_DEFINE_SYSCALL1_NORET(name, arg1_t, arg1)                                                  \
	enum linux_error_t linux_ ## name(arg1_t const arg1)                                             \
	{                                                                                                \
		linux_word_t const ret = linux_syscall1(LINUX_PARAM(arg1), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                   \
			return (enum linux_error_t)-ret;                                                 \
		return linux_error_none;                                                                 \
	}
#define LINUX_DEFINE_SYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2)                                                       \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2)                                             \
	{                                                                                                                   \
		linux_word_t const ret = linux_syscall2(LINUX_PARAM(arg1), LINUX_PARAM(arg2), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                      \
			return (enum linux_error_t)-ret;                                                                    \
		return linux_error_none;                                                                                    \
	}
#define LINUX_DEFINE_SYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3)                                                            \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3)                                             \
	{                                                                                                                                      \
		linux_word_t const ret = linux_syscall3(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                         \
			return (enum linux_error_t)-ret;                                                                                       \
		return linux_error_none;                                                                                                       \
	}
#define LINUX_DEFINE_SYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4)                                                                 \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4)                                             \
	{                                                                                                                                                         \
		linux_word_t const ret = linux_syscall4(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                          \
		return linux_error_none;                                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5)                                                                      \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5)                                             \
	{                                                                                                                                                                            \
		linux_word_t const ret = linux_syscall5(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                               \
			return (enum linux_error_t)-ret;                                                                                                                             \
		return linux_error_none;                                                                                                                                             \
	}
#define LINUX_DEFINE_SYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6)                                                                           \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6)                                             \
	{                                                                                                                                                                                               \
		linux_word_t const ret = linux_syscall6(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), LINUX_PARAM(arg6), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                                  \
			return (enum linux_error_t)-ret;                                                                                                                                                \
		return linux_error_none;                                                                                                                                                                \
	}

#ifdef LINUX_ARCH_X86

#define LINUX_DEFINE_VSYSCALL0_NORET(name)                                             \
	enum linux_error_t linux_ ## name ## _v(void)                                  \
	{                                                                              \
		linux_word_t const ret = linux_vsyscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                 \
			return (enum linux_error_t)-ret;                               \
		return linux_error_none;                                               \
	}
#define LINUX_DEFINE_VSYSCALL1_NORET(name, arg1_t, arg1)                                                  \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1)                                        \
	{                                                                                                 \
		linux_word_t const ret = linux_vsyscall1(LINUX_PARAM(arg1), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                    \
			return (enum linux_error_t)-ret;                                                  \
		return linux_error_none;                                                                  \
	}
#define LINUX_DEFINE_VSYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2)                                                       \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2)                                        \
	{                                                                                                                    \
		linux_word_t const ret = linux_vsyscall2(LINUX_PARAM(arg1), LINUX_PARAM(arg2), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                       \
			return (enum linux_error_t)-ret;                                                                     \
		return linux_error_none;                                                                                     \
	}
#define LINUX_DEFINE_VSYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3)                                                            \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3)                                        \
	{                                                                                                                                       \
		linux_word_t const ret = linux_vsyscall3(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                          \
			return (enum linux_error_t)-ret;                                                                                        \
		return linux_error_none;                                                                                                        \
	}
#define LINUX_DEFINE_VSYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4)                                                                 \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4)                                        \
	{                                                                                                                                                          \
		linux_word_t const ret = linux_vsyscall4(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                           \
		return linux_error_none;                                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5)                                                                      \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5)                                        \
	{                                                                                                                                                                             \
		linux_word_t const ret = linux_vsyscall5(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                \
			return (enum linux_error_t)-ret;                                                                                                                              \
		return linux_error_none;                                                                                                                                              \
	}
#define LINUX_DEFINE_VSYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6)                                                                           \
	enum linux_error_t linux_ ## name ## _v(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6)                                        \
	{                                                                                                                                                                                                \
		linux_word_t const ret = linux_vsyscall6(LINUX_PARAM(arg1), LINUX_PARAM(arg2), LINUX_PARAM(arg3), LINUX_PARAM(arg4), LINUX_PARAM(arg5), LINUX_PARAM(arg6), linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                                   \
			return (enum linux_error_t)-ret;                                                                                                                                                 \
		return linux_error_none;                                                                                                                                                                 \
	}

#endif // LINUX_ARCH_X86

// Definition without return value
//------------------------------------------------------------------------------

#endif // !HEADER_LIBLINUX_SYSCALL_H_INCLUDED
