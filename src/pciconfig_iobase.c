#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(pciconfig_iobase, linux_word_t, which, linux_uword_t, bus, linux_uword_t, devfn, linux_word_t);
