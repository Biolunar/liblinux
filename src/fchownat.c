#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(fchownat, int, dfd, char const*, filename, linux_uid_t, user, linux_gid_t, group, int, flag);
