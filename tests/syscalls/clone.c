#include "test.h"

enum TestResult test_available(void)
{
	if (linux_clone(0, 0, 0, 0, 0, 0) == linux_ENOSYS)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_correct_usage(void)
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

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	DO_TEST(test_available);
	DO_TEST(test_correct_usage);

	linux_exit_group(0);
}
