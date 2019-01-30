#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(fchown, unsigned int, fd, linux_uid_t, user, linux_gid_t, group);
