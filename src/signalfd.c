#include <liblinux/linux.h>

extern inline linux_error_t linux_signalfd(linux_fd_t ufd, linux_sigset_t* user_mask, linux_size_t sizemask, linux_fd_t* result);
