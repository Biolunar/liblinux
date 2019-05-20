#include <liblinux/linux.h>

extern inline enum linux_error_t linux_io_uring_setup(uint32_t entries, struct linux_io_uring_params* params, int* result);
