#include "test.h"

static enum TestResult test_available(void)
{
	struct linux_old_timeval t =
	{
		.tv_sec = 0,
		.tv_usec = 0,
	};
	if (linux_select(0, 0, 0, 0, &t, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
