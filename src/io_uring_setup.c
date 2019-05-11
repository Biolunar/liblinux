#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(io_uring_setup, uint32_t, entries, struct linux_io_uring_params*, params, int);
