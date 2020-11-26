#include "test.h"

static enum TestResult test_correct_usage(void)
{
	linux_word_t pid = 0;
	if (linux_clone(linux_SIGCHLD, 0, 0, 0, 0, &pid))
		return TEST_FAILURE;

	if (!pid) // child
		linux_exit_group(TEST_SUCCESS);

	if (linux_waitid(linux_P_ALL, 0, 0, linux_WEXITED, 0))
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
