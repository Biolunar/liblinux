#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(seccomp, unsigned int, op, unsigned int, flags, char const*, uargs, linux_word_t);
