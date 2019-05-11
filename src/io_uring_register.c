#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(io_uring_register, unsigned int, fd, unsigned int, opcode, void*, arg, unsigned int, nr_args, int);
