#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(quotactl, unsigned int, cmd, char const*, special, linux_qid_t, id, void*, addr);
