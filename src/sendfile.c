#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(sendfile, int, out_fd, int, in_fd, linux_off_t*, offset, linux_size_t, count, linux_ssize_t);
