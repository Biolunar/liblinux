#include <liblinux/start.h>
#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	linux_word_t pid;
	if (linux_clone(linux_SIGCHLD, 0, 0, 0, 0, &pid))
		linux_exit_group(1);

	if (pid == 0) // child
		linux_exit_group(0);
	else // parent
	{
		int status = 0;
		if (linux_wait4(-1, &status, 0, 0, 0))
			linux_exit_group(2);
	}

	linux_exit_group(0);
}
