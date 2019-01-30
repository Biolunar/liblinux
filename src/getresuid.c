#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getresuid, linux_uid_t*, ruidp, linux_uid_t*, euidp, linux_uid_t*, suidp);
