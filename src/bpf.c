#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(bpf, int, cmd, union linux_bpf_attr*, uattr, unsigned int, size, int);
