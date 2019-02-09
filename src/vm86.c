#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(vm86, linux_uword_t, cmd, linux_uword_t, arg);
