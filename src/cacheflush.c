#include <liblinux/linux.h>

extern inline enum linux_error_t linux_cacheflush(linux_uword_t start, linux_uword_t end, int flags);
