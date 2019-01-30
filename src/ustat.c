#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(ustat, unsigned int, dev, struct linux_ustat*, ubuf);
