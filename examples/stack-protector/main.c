#include <liblinux/start.h>
#include <liblinux/linux.h>
#include <liblinux/util.h>

#include <stddef.h>
#include <stdint.h>

struct tls
{
	uintptr_t _pad[5];
	uintptr_t canary;
};

static struct tls tls =
{
#if LINUX_BITS_PER_LONG == 32
	.canary = 0xdeadbeef,
#elif LINUX_BITS_PER_LONG == 64
	.canary = 0xdeadbeefcafebabe,
#else
#error "unknown architecture"
#endif
};

noreturn void __stack_chk_fail(void)
{
	char const msg[] = "Stack smashing detected!\n";
	linux_write(2, msg, sizeof msg, 0);
	linux_exit_group(42);
}

void* memset(void* dest, int c, size_t count)
{
	unsigned char* d = dest;
	while (count--)
		*d++ = (unsigned char)c;
	return dest;
}

void* memcpy(void* restrict dest, void const* restrict src, size_t count)
{
	unsigned char* d = dest;
	unsigned char const* s = src;
	while (count--)
		*d++ = *s++;
	return dest;
}

static void foo(void)
{
	char buf[4096];
	memset(buf, 0, 2 * sizeof buf); // RUNTIME ERROR

	linux_read(0, buf, sizeof buf, 0);
}

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

#if defined(LINUX_ARCH_X86)
	struct linux_user_desc ud =
	{
		.entry_number = (unsigned int)-1, // Let the kernel select an index.
		.base_addr = (unsigned int)&tls,
		.limit = 0x000fffff, // 2^20 pages => 4 GiB
		.seg_32bit = 1,
		.contents = 0,
		.read_exec_only = 0,
		.limit_in_pages = 1, // The 'limit' field is in pages.
		.seg_not_present = 0,
		.useable = 1,
	};
	enum linux_error err = linux_set_thread_area(&ud);
	if (err)
	{
		char const msg[] = "linux_set_thread_area failed\n";
		linux_write(2, msg, sizeof msg, 0);
		linux_exit_group(1);
	}
	linux_set_gs(ud.entry_number * 8 + 3); // Multiply by 8 because every entry in the GDT is 8 bytes. Add 3 because of unknown reasons.
#elif defined(LINUX_ARCH_X32) || defined(LINUX_ARCH_X86_64)
	if (linux_arch_prctl(linux_ARCH_SET_FS, (linux_uword_t)&tls))
	{
		char const msg[] = "linux_arch_prctl failed\n";
		linux_write(2, msg, sizeof msg, 0);
		linux_exit_group(1);
	}
#else
#error "unsupported architecture"
#endif

	foo();

	linux_exit_group(0);
}
