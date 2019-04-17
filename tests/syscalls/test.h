#ifndef HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED
#define HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED

#include <liblinux/start.h>
#include <liblinux/linux.h>

#include <stddef.h>
#include <stdint.h>

enum TestResult
{
	TEST_SUCCESS,
	TEST_FAILURE,
	TEST_OTHER_FAILURE,
};

static uint8_t _test_count = 0;

#define DO_TEST(func) do {\
		enum TestResult const err = func();\
		if (err != TEST_SUCCESS) {\
			if (!_test_count)\
				linux_exit_group(UINT8_MAX);\
			else\
				linux_exit_group(++_test_count);\
		}\
	} while(0)

void* memset(void* dst, int ch, size_t count)
{
	for (unsigned char* d = dst; count; --count)
		*d++ = (unsigned char)ch;
	return dst;
}

#endif // !HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED
