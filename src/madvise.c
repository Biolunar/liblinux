#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(madvise, linux_uword_t, start, linux_size_t, len_in, int, behavior);
