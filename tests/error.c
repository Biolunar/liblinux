#include <liblinux/start.h>
#include <liblinux/syscall.h>
#include <liblinux/error.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	linux_word_t err = 0;
	if (linux_syscall_returned_error(err))
		linux_exit_group(1);

	err = -1;
	if (!linux_syscall_returned_error(err))
		linux_exit_group(2);

	err = -linux_error_max;
	if (!linux_syscall_returned_error(err))
		linux_exit_group(3);

	err = -linux_error_max - 1;
	if (linux_syscall_returned_error(err))
		linux_exit_group(4);

	linux_exit_group(0);
}
