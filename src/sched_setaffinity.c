#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(sched_setaffinity, linux_pid_t, pid, unsigned int, len, unsigned long*, user_mask_ptr);
