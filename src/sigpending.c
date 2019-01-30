#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(sigpending, linux_old_sigset_t*, uset);
