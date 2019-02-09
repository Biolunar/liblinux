#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(setfsgid16, linux_old_gid_t, gid, linux_word_t);
