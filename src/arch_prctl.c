#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(arch_prctl, int, option, linux_uword_t, arg2);
