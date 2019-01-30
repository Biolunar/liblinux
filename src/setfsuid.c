#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(setfsuid, linux_uid_t, uid, long);
