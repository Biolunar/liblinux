#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(fchmod, unsigned int, fd, linux_umode_t, mode);
