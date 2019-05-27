#include <liblinux/linux.h>

extern inline enum linux_error linux_io_uring_enter(unsigned int fd, uint32_t to_submit, uint32_t min_complete, uint32_t flags, linux_sigset_t const* sig, linux_size_t sigsz, int* result);
