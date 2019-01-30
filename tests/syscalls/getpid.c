#include <liblinux/start.h>
#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	linux_pid_t pid = 0;
	if (linux_getpid(&pid))
		linux_exit_group(1);

	if (pid == 0)
		linux_exit_group(2);

	linux_exit_group(0);
}
