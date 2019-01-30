#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(statfs, char const*, pathname, struct linux_statfs*, buf);
