#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(socketcall, int, call, unsigned long*, args, int);
