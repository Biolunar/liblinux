#include <liblinux/linux.h>

extern inline enum linux_error linux_signalfd4_v(linux_fd_t ufd, linux_sigset_t* user_mask, linux_size_t sizemask, uint32_t flags, linux_fd_t* result);
