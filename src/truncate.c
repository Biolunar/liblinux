#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(truncate, char const*, path, linux_word_t, length);
