#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(ftruncate, unsigned int, fd, linux_uword_t, length);
