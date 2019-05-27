#include <liblinux/linux.h>

extern inline enum linux_error linux_msync(linux_uword_t start, linux_size_t len, int flags);
