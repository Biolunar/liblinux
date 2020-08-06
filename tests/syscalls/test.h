#ifndef HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED
#define HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED

#define LINUX_ENABLE_REMOVED
#include <liblinux/start.h>
#include <liblinux/linux.h>

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

enum TestResult
{
	TEST_SUCCESS       = 0,
	TEST_NOT_SUPPORTED = 1,
	TEST_OTHER_FAILURE = 2,
	TEST_FAILURE       = 3,
};

void* memset(void* dst, int ch, size_t count);
void* memcpy(void* restrict dst, void const* restrict src, size_t count);

#define BEGIN_TEST() noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[]) {\
	(void)argc;\
	(void)argv;\
	(void)envp;\
	bool verbose = argc > 1 ? true : false;\
	enum TestResult err = TEST_SUCCESS;\
	uint8_t ret = (uint8_t)err;

#define END_TEST() linux_exit_group(ret); }
#define TEST_LOG(msg) do { if (verbose) {\
			char const m[] = msg;\
			linux_write(1, m, sizeof m, 0);\
		} } while(0)\

#define DO_TEST(func, desc) \
	do {\
		TEST_LOG(desc "... ");\
		err = func();\
		if (verbose) {\
			switch (err) {\
				case TEST_SUCCESS:       TEST_LOG("\x1b[32mSUCCESS\x1b[0m\n");       break;\
				case TEST_NOT_SUPPORTED: TEST_LOG("\x1b[33mNOT SUPPORTED\x1b[0m\n"); break;\
				case TEST_FAILURE:       TEST_LOG("\x1b[31mFAILURE\x1b[0m\n");       break;\
				case TEST_OTHER_FAILURE: TEST_LOG("\x1b[31mOTHER FAILURE\x1b[0m\n"); break;\
			}\
		}\
		if (ret == TEST_SUCCESS) ret = (uint8_t)err;\
	} while(0)

void* memset(void* dst, int ch, size_t count)
{
	for (unsigned char* d = dst; count; --count)
		*d++ = (unsigned char)ch;
	return dst;
}
void* memcpy(void* restrict dst, void const* restrict src, size_t count)
{
	unsigned char const* s = src;
	for (unsigned char* d = dst; count; --count, ++d, ++s)
		*d = *s;
	return dst;
}

#endif // !HEADER_LIBLINUX_TESTS_SYSCALLS_TEST_H_INCLUDED
