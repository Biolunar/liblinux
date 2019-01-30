#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getcpu, unsigned int*, cpup, unsigned int*, nodep, struct linux_getcpu_cache*, unused);
