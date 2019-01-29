#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(semtimedop, int, semid, struct linux_sembuf*, tsops, unsigned int, nsops, struct linux_kernel_timespec const*, timeout);
