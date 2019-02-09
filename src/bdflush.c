#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(bdflush, int, func, linux_word_t, data);
