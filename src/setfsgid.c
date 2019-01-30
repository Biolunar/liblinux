#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(setfsgid, linux_gid_t, gid, long);
