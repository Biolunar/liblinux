#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(setregid16, linux_old_gid_t, rgid, linux_old_gid_t, egid);
