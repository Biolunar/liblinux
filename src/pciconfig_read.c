#include <liblinux/linux.h>

extern inline linux_error_t linux_pciconfig_read(linux_uword_t bus, linux_uword_t dfn, linux_uword_t off, linux_uword_t len, void* buf);
