#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(prctl, int, option, linux_uword_t, arg2, linux_uword_t, arg3, linux_uword_t, arg4, linux_uword_t, arg5, linux_word_t);
