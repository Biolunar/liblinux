#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(semget, linux_key_t, key, int, nsems, int, semflg, long);
