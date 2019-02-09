#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_RET(socketcall, int, call, linux_uword_t*, args, int);
