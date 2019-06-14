#include <liblinux/linux.h>

extern inline enum linux_error linux_kexec_file_load(linux_fd_t kernel_fd, linux_fd_t initrd_fd, linux_uword_t cmdline_len, char const* cmdline_ptr, linux_uword_t flags);
