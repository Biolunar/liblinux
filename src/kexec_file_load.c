#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(kexec_file_load, int, kernel_fd, int, initrd_fd, linux_uword_t, cmdline_len, char const*, cmdline_ptr, linux_uword_t, flags);
