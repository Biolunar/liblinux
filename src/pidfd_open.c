#include <liblinux/linux.h>

extern inline linux_error_t linux_pidfd_open(linux_pid_t pid, unsigned int flags, linux_fd_t* result);
