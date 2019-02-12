#ifndef HEADER_LIBLINUX_TESTS_SYSCALLS_MEMSET_H_INCLUDED
#define HEADER_LIBLINUX_TESTS_SYSCALLS_MEMSET_H_INCLUDED

#include <stddef.h>

void* memset(void* dst, int ch, size_t count)
{
	for (unsigned char* d = dst; count; --count)
		*d++ = (unsigned char)ch;
	return dst;
}

#endif // !HEADER_LIBLINUX_TESTS_SYSCALLS_MEMSET_H_INCLUDED
