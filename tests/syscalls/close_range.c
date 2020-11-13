#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_close_range(0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	if (linux_close_range(0, 2, 0))
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
