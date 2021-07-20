#include <liblinux/linux.h>

extern inline linux_error_t linux_io_uring_setup(uint32_t entries, struct linux_io_uring_params* params, linux_fd_t* result);
