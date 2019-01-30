#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(copy_file_range, int, fd_in, linux_loff_t*, off_in, int, fd_out, linux_loff_t*, off_out, linux_size_t, len, unsigned int, flags, linux_ssize_t);
