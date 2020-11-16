#include <liblinux/start.h>
#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	char const msg[] = "Hello, world!\n";
	linux_write(1, msg, sizeof msg, 0);

	linux_exit_group(0);
}
