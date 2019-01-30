#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(lookup_dcookie, uint64_t, cookie64, char*, buf, linux_size_t, len, int);
