#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(setfsuid16, linux_old_uid_t, uid, long);
