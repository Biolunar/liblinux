#include <liblinux/linux.h>

extern inline enum linux_error_t linux_mremap(linux_uword_t addr, linux_uword_t old_len, linux_uword_t new_len, linux_uword_t flags, linux_uword_t new_addr, linux_uword_t* result);
