#include "test.h"

enum TestResult test_available(void)
{
	struct linux_kernel_timespec const ts = {.tv_nsec = 1};
	if (linux_clock_nanosleep(0, 0, &ts, 0) == linux_ENOSYS)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_correct_usage(void)
{
	struct linux_kernel_timespec const ts = {.tv_nsec = 1};
	struct linux_kernel_timespec rem = {.tv_nsec = 0};
	if (linux_clock_nanosleep(linux_CLOCK_MONOTONIC, 0, &ts, &rem))
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
