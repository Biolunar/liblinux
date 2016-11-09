#ifndef HEADER_LIBLINUX_SYSCALLS_SYSCALLS_H_INCLUDED
#define HEADER_LIBLINUX_SYSCALLS_SYSCALLS_H_INCLUDED

#include "error.h"
#include "syscall_names.h"

#include <stdint.h>

uintptr_t linux_syscall0(uintptr_t num);
uintptr_t linux_syscall1(uintptr_t num, uintptr_t arg1);
uintptr_t linux_syscall2(uintptr_t num, uintptr_t arg1, uintptr_t arg2);
uintptr_t linux_syscall3(uintptr_t num, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3);
uintptr_t linux_syscall4(uintptr_t num, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4);
uintptr_t linux_syscall5(uintptr_t num, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5);
uintptr_t linux_syscall6(uintptr_t num, uintptr_t arg1, uintptr_t arg2, uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, uintptr_t arg6);

#define linux_detail_implement_syscall0_ret(name, ret_t) \
static inline enum linux_error_t linux_ ## name(ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall1_ret(name, arg1_t, arg1, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall1(linux_syscall_name_ ## name, (uintptr_t)arg1); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall2_ret(name, arg1_t, arg1, arg2_t, arg2, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall2(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall3_ret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall3(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall4_ret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall4(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall5_ret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall5(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall6_ret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6, ret_t) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6, ret_t* const result) \
{ \
	uintptr_t const ret = linux_syscall6(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, (uintptr_t)arg6); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	if (result) \
		*result = (ret_t)ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall0_noret(name) \
static inline enum linux_error_t linux_ ## name(void) \
{ \
	uintptr_t const ret = linux_syscall0(linux_syscall_name_ ## name); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall1_noret(name, arg1_t, arg1) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1) \
{ \
	uintptr_t const ret = linux_syscall1(linux_syscall_name_ ## name, (uintptr_t)arg1); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall2_noret(name, arg1_t, arg1, arg2_t, arg2) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2) \
{ \
	uintptr_t const ret = linux_syscall2(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall3_noret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3) \
{ \
	uintptr_t const ret = linux_syscall3(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall4_noret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4) \
{ \
	uintptr_t const ret = linux_syscall4(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall5_noret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5) \
{ \
	uintptr_t const ret = linux_syscall5(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}
#define linux_detail_implement_syscall6_noret(name, arg1_t, arg1, arg2_t, arg2, arg3_t, arg3, arg4_t, arg4, arg5_t, arg5, arg6_t, arg6) \
static inline enum linux_error_t linux_ ## name(arg1_t const arg1, arg2_t const arg2, arg3_t const arg3, arg4_t const arg4, arg5_t const arg5, arg6_t const arg6) \
{ \
	uintptr_t const ret = linux_syscall6(linux_syscall_name_ ## name, (uintptr_t)arg1, (uintptr_t)arg2, (uintptr_t)arg3, (uintptr_t)arg4, (uintptr_t)arg5, (uintptr_t)arg6); \
	if (linux_syscall_returned_error(ret)) \
		return (enum linux_error_t)-ret; \
	return linux_error_none; \
}

#endif // !HEADER_LIBLINUX_SYSCALLS_SYSCALLS_H_INCLUDED
