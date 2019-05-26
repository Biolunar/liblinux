#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_clone(0, 0, 0, 0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	linux_word_t pid;
	if (linux_clone(linux_SIGCHLD, 0, 0, 0, 0, &pid))
		return TEST_FAILURE;

	if (pid == 0) // child
		linux_exit_group(0);
	else // parent
	{
		int status = 0;
		if (linux_wait4(-1, &status, 0, 0, 0))
			return TEST_OTHER_FAILURE;
	}

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
