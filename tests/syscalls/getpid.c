#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_getpid(0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	linux_pid_t pid = 0;
	if (linux_getpid(&pid))
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
