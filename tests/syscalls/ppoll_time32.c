#include "test.h"

static enum TestResult test_available(void)
{
	struct linux_timespec32 t = { .tv_nsec = 1 };
	if (linux_ppoll_time32(0, 0, &t, 0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
