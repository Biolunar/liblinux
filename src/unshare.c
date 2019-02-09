#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(unshare, linux_uword_t, unshare_flags);
