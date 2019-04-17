#include "test.h"

enum TestResult test_available(void)
{
	if (linux_getpid(0) == linux_ENOSYS)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_correct_usage(void)
{
	linux_pid_t pid = 0;
	if (linux_getpid(&pid))
		return TEST_FAILURE;

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
