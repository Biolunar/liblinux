#include <liblinux/linux.h>

extern inline enum linux_error_t linux_io_uring_register(unsigned int fd, unsigned int opcode, void* arg, unsigned int nr_args, int* result);
