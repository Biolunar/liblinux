#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(clone, unsigned long, clone_flags, unsigned long, newsp, int*, parent_tidptr, int*, child_tidptr, unsigned long, tls, long);
