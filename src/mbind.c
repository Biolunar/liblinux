#include <liblinux/linux.h>

extern inline linux_error_t linux_mbind(linux_uword_t start, linux_uword_t len, linux_uword_t mode, linux_uword_t const* nmask, linux_uword_t maxnode, unsigned int flags);
