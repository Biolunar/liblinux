#include <liblinux/linux.h>

extern inline enum linux_error linux_io_uring_register(linux_fd_t fd, unsigned int opcode, void* arg, unsigned int nr_args, int* result);
