#include <liblinux/linux.h>

extern inline enum linux_error_t linux_kexec_file_load(int kernel_fd, int initrd_fd, linux_uword_t cmdline_len, char const* cmdline_ptr, linux_uword_t flags);
