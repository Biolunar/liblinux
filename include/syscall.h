#ifndef HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED

#include "error.h"
#include "names.h"

#include <stdint.h>
#include <stdnoreturn.h>

//------------------------------------------------------------------------------
// Generic functions

uintptr_t linux_syscall0(uintptr_t num);
uintptr_t linux_syscall1(uintptr_t arg1, uintptr_t num);
uintptr_t linux_syscall2(uintptr_t arg1, uintptr_t arg2, uintptr_t num);
uintptr_t linux_syscall3(uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t num);
uintptr_t linux_syscall4(uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t num);
uintptr_t linux_syscall5(uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t num);
uintptr_t linux_syscall6(uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6, uintptr_t num);

// Generic functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Direct functions

noreturn void linux_exit(uintptr_t error_code);
noreturn void linux_exit_group(uintptr_t error_code);

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
	enum linux_error_t linux_ ## name()
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

#define LINUX_DEFINE_SYSCALL0_RET(name, ret_t)                                     \
	enum linux_error_t linux_ ## name(ret_t* const result)                     \
	{                                                                          \
		uintptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                             \
			return (enum linux_error_t)-ret;                           \
		if (result)                                                        \
			*result = (ret_t)ret;                                      \
		return linux_error_none;                                           \
	}
#define LINUX_DEFINE_SYSCALL1_RET(name, arg1_t, arg1, ret_t)                                        \
	enum linux_error_t linux_ ## name(arg1_t const arg1, ret_t* const result)                   \
	{                                                                                           \
		uintptr_t const ret = linux_syscall1((uintptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                              \
			return (enum linux_error_t)-ret;                                            \
		if (result)                                                                         \
			*result = (ret_t)ret;                                                       \
		return linux_error_none;                                                            \
	}
#define LINUX_DEFINE_SYSCALL2_RET(name, arg1_t, arg1, arg2_t, arg2, ret_t)                                           \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, ret_t* const result)                 \
	{                                                                                                            \
		uintptr_t const ret = linux_syscall2((uintptr_t)arg1, (uintptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                               \
			return (enum linux_error_t)-ret;                                                             \
		if (result)                                                                                          \
			*result = (ret_t)ret;                                                                        \
		return linux_error_none;                                                                             \
	}
#define LINUX_DEFINE_SYSCALL3_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t)                                              \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result)               \
	{                                                                                                                             \
		uintptr_t const ret = linux_syscall3((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                \
			return (enum linux_error_t)-ret;                                                                              \
		if (result)                                                                                                           \
			*result = (ret_t)ret;                                                                                         \
		return linux_error_none;                                                                                              \
	}
#define LINUX_DEFINE_SYSCALL4_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t)                                                   \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result)               \
	{                                                                                                                                                \
		uintptr_t const ret = linux_syscall4((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, linux_syscall_name_ ## name);   \
		if (linux_syscall_returned_error(ret))                                                                                                   \
			return (enum linux_error_t)-ret;                                                                                                 \
		if (result)                                                                                                                              \
			*result = (ret_t)ret;                                                                                                            \
		return linux_error_none;                                                                                                                 \
	}
#define LINUX_DEFINE_SYSCALL5_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t)                                                        \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result)               \
	{                                                                                                                                                                   \
		uintptr_t const ret = linux_syscall5((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, linux_syscall_name_ ## name);     \
		if (linux_syscall_returned_error(ret))                                                                                                                      \
			return (enum linux_error_t)-ret;                                                                                                                    \
		if (result)                                                                                                                                                 \
			*result = (ret_t)ret;                                                                                                                               \
		return linux_error_none;                                                                                                                                    \
	}
#define LINUX_DEFINE_SYSCALL6_RET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t)                                                             \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result)               \
	{                                                                                                                                                                                      \
		uintptr_t const ret = linux_syscall6((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, (uintptr_t)arg6, linux_syscall_name_ ## name);       \
		if (linux_syscall_returned_error(ret))                                                                                                                                         \
			return (enum linux_error_t)-ret;                                                                                                                                       \
		if (result)                                                                                                                                                                    \
			*result = (ret_t)ret;                                                                                                                                                  \
		return linux_error_none;                                                                                                                                                       \
	}

// Definition with return value
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definition without return value

#define LINUX_DEFINE_SYSCALL0_NORET(name)                                          \
	enum linux_error_t linux_ ## name(void)                                    \
	{                                                                          \
		uintptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                             \
			return (enum linux_error_t)-ret;                           \
		return linux_error_none;                                           \
	}
#define LINUX_DEFINE_SYSCALL1_NORET(name, arg1_t, arg1)                                             \
	enum linux_error_t linux_ ## name(arg1_t const arg1)                                        \
	{                                                                                           \
		uintptr_t const ret = linux_syscall1((uintptr_t)arg1, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                              \
			return (enum linux_error_t)-ret;                                            \
		return linux_error_none;                                                            \
	}
#define LINUX_DEFINE_SYSCALL2_NORET(name, arg1_t, arg1, arg2_t, arg2)                                                \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2)                                      \
	{                                                                                                            \
		uintptr_t const ret = linux_syscall2((uintptr_t)arg1, (uintptr_t)arg2, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                               \
			return (enum linux_error_t)-ret;                                                             \
		return linux_error_none;                                                                             \
	}
#define LINUX_DEFINE_SYSCALL3_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3)                                                   \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3)                                    \
	{                                                                                                                             \
		uintptr_t const ret = linux_syscall3((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                \
			return (enum linux_error_t)-ret;                                                                              \
		return linux_error_none;                                                                                              \
	}
#define LINUX_DEFINE_SYSCALL4_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4)                                                      \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4)                                  \
	{                                                                                                                                              \
		uintptr_t const ret = linux_syscall4((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                 \
			return (enum linux_error_t)-ret;                                                                                               \
		return linux_error_none;                                                                                                               \
	}
#define LINUX_DEFINE_SYSCALL5_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5)                                                         \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5)                                \
	{                                                                                                                                                               \
		uintptr_t const ret = linux_syscall5((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                  \
			return (enum linux_error_t)-ret;                                                                                                                \
		return linux_error_none;                                                                                                                                \
	}
#define LINUX_DEFINE_SYSCALL6_NORET(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6)                                                            \
	enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6)                              \
	{                                                                                                                                                                                \
		uintptr_t const ret = linux_syscall6((uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, (uintptr_t)arg6, linux_syscall_name_ ## name); \
		if (linux_syscall_returned_error(ret))                                                                                                                                   \
			return (enum linux_error_t)-ret;                                                                                                                                 \
		return linux_error_none;                                                                                                                                                 \
	}

// Definition without return value
//------------------------------------------------------------------------------

#endif // !HEADER_LIBLINUX_SYSCALL_SYSCALL_H_INCLUDED
