#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(ptrace, linux_word_t, request, linux_word_t, pid, linux_uword_t, addr, linux_uword_t, data, linux_word_t);
