#include <liblinux/linux.h>

extern inline enum linux_error linux_pidfd_open(linux_pid_t pid, unsigned int flags, linux_fd_t* result);
