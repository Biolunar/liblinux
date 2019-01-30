#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(splice, int, fd_in, linux_loff_t*, off_in, int, fd_out, linux_loff_t*, off_out, linux_size_t, len, unsigned int, flags, long);
