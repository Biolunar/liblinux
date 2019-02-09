#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(pciconfig_write, linux_uword_t, bus, linux_uword_t, dfn, linux_uword_t, off, linux_uword_t, len, void*, buf);
