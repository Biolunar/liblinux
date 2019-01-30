#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getresuid16, linux_old_uid_t*, ruidp, linux_old_uid_t*, euidp, linux_old_uid_t*, suidp);
