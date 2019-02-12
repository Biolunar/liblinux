#include <liblinux/start.h>
#include <liblinux/linux.h>

#include "memset.h"

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	struct linux_kernel_timespec const ts = {.tv_nsec = 1};
	struct linux_kernel_timespec rem = {.tv_nsec = 0};
	if (linux_clock_nanosleep(linux_CLOCK_MONOTONIC, 0, &ts, &rem))
		linux_exit_group(1);

	linux_exit_group(0);
}
