#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(mq_open, char const*, u_name, int, oflag, linux_umode_t, mode, struct linux_mq_attr*, u_attr, int);
