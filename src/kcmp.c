#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(kcmp, linux_pid_t, pid1, linux_pid_t, pid2, int, type, linux_uword_t, idx1, linux_uword_t, idx2, int);
