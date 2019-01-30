#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(setresuid, linux_uid_t, ruid, linux_uid_t, euid, linux_uid_t, suid);
