#include <liblinux/linux.h>

extern inline linux_error_t linux_mprotect(linux_uword_t start, linux_size_t len, linux_uword_t prot);
