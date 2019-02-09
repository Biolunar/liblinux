#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(munlock, linux_uword_t, start, linux_size_t, len);
