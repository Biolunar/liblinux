#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(signal, int, sig, linux_sighandler_t, handler, linux_uword_t);
