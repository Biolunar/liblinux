#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(lchown, char const*, filename, linux_uid_t, user, linux_gid_t, group);
