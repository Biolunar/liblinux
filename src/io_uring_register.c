#include <liblinux/linux.h>

extern inline linux_error_t linux_io_uring_register(linux_fd_t fd, unsigned int opcode, void* arg, unsigned int nr_args, int* result);
