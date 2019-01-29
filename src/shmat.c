#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(shmat, int, shmid, char*, shmaddr, int, shmflg, long);
