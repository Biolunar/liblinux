#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(getpriority, int, which, int, who, linux_word_t);
