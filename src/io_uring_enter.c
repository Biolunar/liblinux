#include <liblinux/linux.h>

extern inline linux_error_t linux_io_uring_enter(linux_fd_t fd, uint32_t to_submit, uint32_t min_complete, uint32_t flags, linux_sigset_t const* sig, linux_size_t sigsz, int* result);
