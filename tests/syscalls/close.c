#include <liblinux/start.h>
#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	if (linux_close(0))
		linux_exit_group(1);

	linux_exit_group(0);
}
