#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(kexec_file_load, int, kernel_fd, int, initrd_fd, unsigned long, cmdline_len, char const*, cmdline_ptr, unsigned long, flags);
