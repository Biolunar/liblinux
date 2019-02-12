#include <liblinux/start.h>
#include <liblinux/linux.h>

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	linux_size_t const len = sizeof(int);
	linux_uword_t ret;
#if defined(LINUX_ARCH_ARM_EABI) || defined(LINUX_ARCH_X86)
	if (linux_mmap_pgoff(0, len, linux_PROT_READ | linux_PROT_WRITE, linux_MAP_ANONYMOUS | linux_MAP_PRIVATE, 0, 0, &ret))
#else
	if (linux_mmap(0, len, linux_PROT_READ | linux_PROT_WRITE, linux_MAP_ANONYMOUS | linux_MAP_PRIVATE, 0, 0, &ret))
#endif
		linux_exit_group(1);

	int volatile* p = (int volatile*)(uintptr_t)ret;
	*p = 42;

	if (linux_munmap(ret, len))
		linux_exit_group(2);

	linux_exit_group(0);
}
