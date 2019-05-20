#include <liblinux/linux.h>

extern inline enum linux_error_t linux_get_mempolicy(int* policy, linux_uword_t* nmask, linux_uword_t maxnode, linux_uword_t addr, linux_uword_t flags);
