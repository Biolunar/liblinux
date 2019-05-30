#include "test.h"

static enum TestResult test_available(void)
{
	struct linux_kernel_timespec const t = { .tv_nsec = 1 };
	if (linux_nanosleep(&t, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
