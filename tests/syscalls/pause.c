#include "test.h"

static void handler(int sig)
{
	(void)sig;
}

static enum TestResult test_available(void)
{
	struct linux_sigaction sa =
	{
		.sa_handler = &handler,
		.sa_flags = linux_SA_RESTORER,
		.sa_restorer = &linux_rt_sigreturn,
	};
	linux_sigemptyset(&sa.sa_mask);
	if (linux_rt_sigaction(linux_SIGALRM, &sa, 0, sizeof(linux_sigset_t)))
		return TEST_OTHER_FAILURE;

	struct linux_old_itimerval const t = { .it_value = { .tv_usec = 50 * 1000 } }; // 50ms
	if (linux_setitimer(linux_ITIMER_REAL, &t, 0))
		return TEST_OTHER_FAILURE;

	if (linux_pause() == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is supported");
END_TEST()
