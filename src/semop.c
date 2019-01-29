#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(semop, int, semid, struct linux_sembuf*, tsops, unsigned, nsops);
