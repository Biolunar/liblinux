#include <liblinux/linux.h>

extern inline linux_error_t linux_madvise(linux_uword_t start, linux_size_t len_in, int behavior);
