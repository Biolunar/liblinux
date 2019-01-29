#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(process_vm_writev, linux_pid_t, pid, struct linux_iovec const*, lvec, unsigned long, liovcnt, struct linux_iovec const*, rvec, unsigned long, riovcnt, unsigned long, flags, linux_ssize_t);
