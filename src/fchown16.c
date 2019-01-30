#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(fchown16, unsigned int, fd, linux_old_uid_t, user, linux_old_gid_t, group);
