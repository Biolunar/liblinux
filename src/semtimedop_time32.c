#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(semtimedop_time32, int, semid, struct linux_sembuf*, tsops, unsigned int, nsops, struct linux_old_timespec32 const*, timeout);
