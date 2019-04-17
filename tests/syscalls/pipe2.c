#include "test.h"

enum TestResult test_available(void)
{
	if (linux_pipe2(0, 0) == linux_ENOSYS)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_correct_usage(void)
{
	int fds[2] = {0, 0};
	if (linux_pipe2(fds, linux_O_CLOEXEC))
		return TEST_FAILURE;

	if (linux_close(fds[0]))
		return TEST_OTHER_FAILURE;

	if (linux_close(fds[1]))
		return TEST_OTHER_FAILURE;

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
