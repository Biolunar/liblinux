#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	linux_word_t ret = 0;
	if (linux_get_error(ret))
		linux_exit_group(1);

	ret = -1;
	if (!linux_get_error(ret))
		linux_exit_group(2);

	ret = -4095;
	if (!linux_get_error(ret))
		linux_exit_group(3);

	ret = -4095 - 1;
	if (linux_get_error(ret))
		linux_exit_group(4);

	linux_exit_group(0);
}
