#include "test.h"

static enum TestResult test_available(void)
{
	// Use a random non-zero request, so that qemu doesn't complain about
	// an unsupported ioctl.
	if (linux_ioctl(0, linux_TIOCGPGRP, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
