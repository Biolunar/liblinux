#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(sched_getaffinity, linux_pid_t, pid, unsigned int, len, linux_uword_t*, user_mask_ptr);
