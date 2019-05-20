#include <liblinux/linux.h>

extern inline enum linux_error_t linux_set_mempolicy(int mode, linux_uword_t const* nmask, linux_uword_t maxnode);
