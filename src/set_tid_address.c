#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(set_tid_address, int*, tidptr, linux_pid_t);
