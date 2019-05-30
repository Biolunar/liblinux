#include "test.h"

static enum TestResult test_available(void)
{
	uint32_t filter;
	if (linux_seccomp(linux_SECCOMP_GET_ACTION_AVAIL, 0, &filter, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
