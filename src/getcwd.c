#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(getcwd, char*, buf, linux_uword_t, size, int);
