#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(modify_ldt, int, func, void*, ptr, linux_uword_t, bytecount, int);
