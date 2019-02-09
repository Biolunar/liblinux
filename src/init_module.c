#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(init_module, void*, umod, linux_uword_t, len, char const*, uargs);
