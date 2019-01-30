#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(pipe2, int*, fildes, int, flags);
