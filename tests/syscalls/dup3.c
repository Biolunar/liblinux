#include <liblinux/start.h>
#include <liblinux/linux.h>

#include "memset.h"

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	int fds[2] = {0, 0};
	if (linux_pipe2(fds, linux_O_CLOEXEC))
		linux_exit_group(1);

	int fd = 0;
	if (linux_dup3(fds[0], fds[1], linux_O_CLOEXEC, &fd))
		linux_exit_group(2);

	if (fd != fds[1])
		linux_exit_group(3);

	if (linux_close(fds[0]))
		linux_exit_group(4);

	if (linux_close(fds[1]))
		linux_exit_group(5);

	linux_exit_group(0);
}
