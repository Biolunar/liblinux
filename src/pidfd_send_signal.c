#include <liblinux/linux.h>

extern inline linux_error_t linux_pidfd_send_signal(linux_fd_t pidfd, int sig, linux_siginfo_t* info, unsigned int flags);
