#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(setuid16, linux_old_uid_t, uid);
