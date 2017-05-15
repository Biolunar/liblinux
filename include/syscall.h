/*
 * Copyright 2017 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED

#if __STDC_VERSION__ < 199901L
#error "This library needs at least a C99 compiler."
#endif // __STDC_VERSION__ < 199901L

#include "error.h"
#include "names.h"

#include <stdint.h>
#if __STDC_VERSION__ >= 201112L
#include <stdnoreturn.h>
#else // __STDC_VERSION__ >= 201112L
#define noreturn
#endif // __STDC_VERSION__ >= 201112L

//------------------------------------------------------------------------------
// Generic functions

#ifdef __i386__
void* linux_vsyscall_ptr; // Set this to the __kernel_vsyscall symbol exported by the vDSO or the following functions will segfault.

intptr_t linux_vsyscall0(intptr_t num);
intptr_t linux_vsyscall1(intptr_t arg1, intptr_t num);
intptr_t linux_vsyscall2(intptr_t arg1, intptr_t arg2, intptr_t num);
intptr_t linux_vsyscall3(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t num);
intptr_t linux_vsyscall4(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t num);
intptr_t linux_vsyscall5(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t num);
intptr_t linux_vsyscall6(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6, intptr_t num);
#endif // __i386__
intptr_t linux_syscall0(intptr_t num);
intptr_t linux_syscall1(intptr_t arg1, intptr_t num);
intptr_t linux_syscall2(intptr_t arg1, intptr_t arg2, intptr_t num);
intptr_t linux_syscall3(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t num);
intptr_t linux_syscall4(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t num);
intptr_t linux_syscall5(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t num);
intptr_t linux_syscall6(intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6, intptr_t num);

// Generic functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Direct functions

noreturn void linux_exit(uint8_t status);
noreturn void linux_exit_group(uint8_t status);

// Following functions are intended to be used as the restorer callback in the
// sigaction structure. They call sigreturn or rt_sigreturn internally.
#ifdef __i386__
noreturn void linux_restorer(void);
#endif // __i386__
noreturn void linux_rt_restorer(void);

// Direct functions
//------------------------------------------------------------------------------

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

// Declaration without return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definition with return value

#ifdef __i386__
#define LINUX_DEFINE_VSYSCALL0_RET(name, ret_t)                                    \
	enum linux_error_t linux_ ## name(ret_t* const result)                     \
	{                                                                          \
		intptr_t const ret = linux_vsyscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                             \
			return (enum linux_error_t)-ret;                           \
		if (result)                                                        \
			*result = (ret_t)ret;                                      \
		return linux_error_none;                                           \
	}
#define LINUX_DEFINE_VSYSCALL1_RET(name, arg1_t, arg1, ret_t)                                      \
	enum linux_error_t linux_ ## name(arg1_t const arg1, ret_t* const result)                  \
	{                                                                                          \
		intptr_t const ret = linux_vsyscall1((intptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                             \
			return (enum linux_error_t)-ret;                                           \
		if (result)                                                                        \
			*result = (ret_t)ret;                                                      \
		return linux_error_none;                                                           \
	}
#define LINUX_DEFINE_VSYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t)                                        \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, ret_t* const result)               \
	{                                                                                                          \
		intptr_t const ret = linux_vsyscall2((intptr_t)arg1, (intptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                             \
			return (enum linux_error_t)-ret;                                                           \
		if (result)                                                                                        \
			*result = (ret_t)ret;                                                                      \
		return linux_error_none;                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t)                                          \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result)            \
	{                                                                                                                          \
		intptr_t const ret = linux_vsyscall3((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                             \
			return (enum linux_error_t)-ret;                                                                           \
		if (result)                                                                                                        \
			*result = (ret_t)ret;                                                                                      \
		return linux_error_none;                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t)                                            \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result)         \
	{                                                                                                                                          \
		intptr_t const ret = linux_vsyscall4((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                             \
			return (enum linux_error_t)-ret;                                                                                           \
		if (result)                                                                                                                        \
			*result = (ret_t)ret;                                                                                                      \
		return linux_error_none;                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t)                                              \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result)      \
	{                                                                                                                                                          \
		intptr_t const ret = linux_vsyscall5((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                           \
		if (result)                                                                                                                                        \
			*result = (ret_t)ret;                                                                                                                      \
		return linux_error_none;                                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t)                                                \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result)   \
	{                                                                                                                                                                          \
		intptr_t const ret = linux_vsyscall6((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, (intptr_t)arg6, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                                           \
		if (result)                                                                                                                                                        \
			*result = (ret_t)ret;                                                                                                                                      \
		return linux_error_none;                                                                                                                                           \
	}
#endif // __i386__
#define LINUX_DEFINE_SYSCALL0_RET(name, ret_t)                                    \
	enum linux_error_t linux_ ## name(ret_t* const result)                    \
	{                                                                         \
		intptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                            \
			return (enum linux_error_t)-ret;                          \
		if (result)                                                       \
			*result = (ret_t)ret;                                     \
		return linux_error_none;                                          \
	}
#define LINUX_DEFINE_SYSCALL1_RET(name, arg1_t, arg1, ret_t)                                      \
	enum linux_error_t linux_ ## name(arg1_t const arg1, ret_t* const result)                 \
	{                                                                                         \
		intptr_t const ret = linux_syscall1((intptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                            \
			return (enum linux_error_t)-ret;                                          \
		if (result)                                                                       \
			*result = (ret_t)ret;                                                     \
		return linux_error_none;                                                          \
	}
#define LINUX_DEFINE_SYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t)                                        \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, ret_t* const result)              \
	{                                                                                                         \
		intptr_t const ret = linux_syscall2((intptr_t)arg1, (intptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                            \
			return (enum linux_error_t)-ret;                                                          \
		if (result)                                                                                       \
			*result = (ret_t)ret;                                                                     \
		return linux_error_none;                                                                          \
	}
#define LINUX_DEFINE_SYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t)                                          \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result)           \
	{                                                                                                                         \
		intptr_t const ret = linux_syscall3((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                            \
			return (enum linux_error_t)-ret;                                                                          \
		if (result)                                                                                                       \
			*result = (ret_t)ret;                                                                                     \
		return linux_error_none;                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t)                                            \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result)        \
	{                                                                                                                                         \
		intptr_t const ret = linux_syscall4((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                            \
			return (enum linux_error_t)-ret;                                                                                          \
		if (result)                                                                                                                       \
			*result = (ret_t)ret;                                                                                                     \
		return linux_error_none;                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t)                                              \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result)     \
	{                                                                                                                                                         \
		intptr_t const ret = linux_syscall5((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                          \
		if (result)                                                                                                                                       \
			*result = (ret_t)ret;                                                                                                                     \
		return linux_error_none;                                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t)                                                \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result)  \
	{                                                                                                                                                                         \
		intptr_t const ret = linux_syscall6((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, (intptr_t)arg6, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                                          \
		if (result)                                                                                                                                                       \
			*result = (ret_t)ret;                                                                                                                                     \
		return linux_error_none;                                                                                                                                          \
	}

// Definition with return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definition without return value

#ifdef __i386__
#define LINUX_DEFINE_VSYSCALL0_NORET(name)                                         \
	enum linux_error_t linux_ ## name(void)                                    \
	{                                                                          \
		intptr_t const ret = linux_vsyscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                             \
			return (enum linux_error_t)-ret;                           \
		return linux_error_none;                                           \
	}
#define LINUX_DEFINE_VSYSCALL1_NORET(name, arg1_t, arg1)                                           \
	enum linux_error_t linux_ ## name(arg1_t const arg1)                                       \
	{                                                                                          \
		intptr_t const ret = linux_vsyscall1((intptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                             \
			return (enum linux_error_t)-ret;                                           \
		return linux_error_none;                                                           \
	}
#define LINUX_DEFINE_VSYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2)                                             \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2)                                    \
	{                                                                                                          \
		intptr_t const ret = linux_vsyscall2((intptr_t)arg1, (intptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                             \
			return (enum linux_error_t)-ret;                                                           \
		return linux_error_none;                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3)                                               \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3)                                 \
	{                                                                                                                          \
		intptr_t const ret = linux_vsyscall3((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                             \
			return (enum linux_error_t)-ret;                                                                           \
		return linux_error_none;                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4)                                                 \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4)                              \
	{                                                                                                                                          \
		intptr_t const ret = linux_vsyscall4((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                             \
			return (enum linux_error_t)-ret;                                                                                           \
		return linux_error_none;                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5)                                                   \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5)                           \
	{                                                                                                                                                          \
		intptr_t const ret = linux_vsyscall5((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                           \
		return linux_error_none;                                                                                                                           \
	}
#define LINUX_DEFINE_VSYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6)                                                     \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6)                        \
	{                                                                                                                                                                          \
		intptr_t const ret = linux_vsyscall6((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, (intptr_t)arg6, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                             \
			return (enum linux_error_t)-ret;                                                                                                                           \
		return linux_error_none;                                                                                                                                           \
	}
#endif // __i386__
#define LINUX_DEFINE_SYSCALL0_NORET(name)                                         \
	enum linux_error_t linux_ ## name(void)                                   \
	{                                                                         \
		intptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                            \
			return (enum linux_error_t)-ret;                          \
		return linux_error_none;                                          \
	}
#define LINUX_DEFINE_SYSCALL1_NORET(name, arg1_t, arg1)                                           \
	enum linux_error_t linux_ ## name(arg1_t const arg1)                                      \
	{                                                                                         \
		intptr_t const ret = linux_syscall1((intptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                            \
			return (enum linux_error_t)-ret;                                          \
		return linux_error_none;                                                          \
	}
#define LINUX_DEFINE_SYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2)                                             \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2)                                   \
	{                                                                                                         \
		intptr_t const ret = linux_syscall2((intptr_t)arg1, (intptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                            \
			return (enum linux_error_t)-ret;                                                          \
		return linux_error_none;                                                                          \
	}
#define LINUX_DEFINE_SYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3)                                               \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3)                                \
	{                                                                                                                         \
		intptr_t const ret = linux_syscall3((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                            \
			return (enum linux_error_t)-ret;                                                                          \
		return linux_error_none;                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4)                                                 \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4)                             \
	{                                                                                                                                         \
		intptr_t const ret = linux_syscall4((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                            \
			return (enum linux_error_t)-ret;                                                                                          \
		return linux_error_none;                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5)                                                   \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5)                          \
	{                                                                                                                                                         \
		intptr_t const ret = linux_syscall5((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                          \
		return linux_error_none;                                                                                                                          \
	}
#define LINUX_DEFINE_SYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6)                                                     \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6)                       \
	{                                                                                                                                                                         \
		intptr_t const ret = linux_syscall6((intptr_t)arg1, (intptr_t)arg2, (intptr_t)arg3, (intptr_t)arg4, (intptr_t)arg5, (intptr_t)arg6, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                            \
			return (enum linux_error_t)-ret;                                                                                                                          \
		return linux_error_none;                                                                                                                                          \
	}

// Definition without return value
//------------------------------------------------------------------------------

#endif // !HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED
