#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_RET(old_mmap, struct linux_mmap_arg_struct*, arg, unsigned long);
