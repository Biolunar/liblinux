#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(pidfd_send_signal, int, pidfd, int, sig, linux_siginfo_t*, info, unsigned int, flags);
