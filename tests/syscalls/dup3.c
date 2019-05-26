#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_dup3(0, 0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	int fds[2] = {0, 0};
	if (linux_pipe2(fds, linux_O_CLOEXEC))
		return TEST_OTHER_FAILURE;

	int fd = 0;
	if (linux_dup3((unsigned int)fds[0], (unsigned int)fds[1], linux_O_CLOEXEC, &fd))
		return TEST_FAILURE;

	if (linux_close((unsigned int)fds[0]))
		return TEST_OTHER_FAILURE;

	if (linux_close((unsigned int)fds[1]))
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
