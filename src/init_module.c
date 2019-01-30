#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(init_module, void*, umod, unsigned long, len, char const*, uargs);
