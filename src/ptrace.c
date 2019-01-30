#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(ptrace, long, request, long, pid, unsigned long, addr, unsigned long, data, long);
