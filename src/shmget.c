#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(shmget, linux_key_t, key, linux_size_t, size, int, shmflg, linux_word_t);
