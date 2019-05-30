#include "test.h"

static enum linux_error fork(linux_pid_t* pid)
{
	linux_word_t result;
	enum linux_error const err = linux_clone(linux_SIGCHLD, 0, 0, 0, 0, &result);
	*pid = (linux_pid_t)result;
	return err;
}

static void handler(int sig)
{
	(void)sig;

	linux_exit_group(TEST_SUCCESS);
}

static enum TestResult test_available(void)
{
	linux_pid_t pid;
	if (fork(&pid))
		return TEST_OTHER_FAILURE;

	if (!pid) // child
	{
		struct linux_sigaction sa =
		{
			.sa_handler = &handler,
			.sa_flags = linux_SA_RESTORER,
			.sa_restorer = &linux_rt_sigreturn,
		};
		linux_sigemptyset(&sa.sa_mask);
		if (linux_rt_sigaction(linux_SIGTRAP, &sa, 0, sizeof(linux_sigset_t)))
			return TEST_OTHER_FAILURE;

		linux_exit_group(linux_breakpoint());
	}

	int status;
	if (linux_wait4(-1, &status, 0, 0, 0))
		return TEST_OTHER_FAILURE;

	if (!linux_WIFEXITED(status))
		return TEST_OTHER_FAILURE;

	if (linux_WEXITSTATUS(status) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
END_TEST()
