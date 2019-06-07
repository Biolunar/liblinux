#include <liblinux/linux.h>

extern inline enum linux_error linux_signalfd4(linux_fd_t ufd, linux_sigset_t* user_mask, linux_size_t sizemask, int flags, linux_fd_t* result);
