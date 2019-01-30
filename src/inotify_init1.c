#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(inotify_init1, int, flags, int);
