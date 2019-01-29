#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_RET(msgget, linux_key_t, key, int, msgflg, long);
