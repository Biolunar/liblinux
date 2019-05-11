#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(io_uring_enter, unsigned int, fd, uint32_t, to_submit, uint32_t, min_complete, uint32_t, flags, linux_sigset_t const*, sig, linux_size_t, sigsz, int);
