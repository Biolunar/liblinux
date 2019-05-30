#include "test.h"

static enum TestResult test_available(void)
{
	// Use a supported level and optname pair for qemu, so that qemu
	// doesn't complain about them.
	if (linux_setsockopt(0, linux_SOL_IP, linux_SO_PRIORITY, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
