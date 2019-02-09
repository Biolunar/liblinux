#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(fcntl64, unsigned int, fd, unsigned int, cmd, linux_uword_t, arg, linux_word_t);
