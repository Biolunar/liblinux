#include "test.h"

static enum TestResult test_available(void)
{
	struct linux_kernel_timespec const ts = {.tv_nsec = 1};
	if (linux_clock_nanosleep(0, 0, &ts, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	struct linux_kernel_timespec const ts = {.tv_nsec = 1};
	struct linux_kernel_timespec rem = {.tv_nsec = 0};
	if (linux_clock_nanosleep(linux_CLOCK_MONOTONIC, 0, &ts, &rem))
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
