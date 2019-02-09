#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(vmsplice, int, fd, struct linux_iovec const*, uiov, linux_uword_t, nr_segs, unsigned int, flags, linux_word_t);
