#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(old_semctl, int, semid, int, semnum, int, cmd, linux_uword_t, arg, linux_word_t);
