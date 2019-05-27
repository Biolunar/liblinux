#include <liblinux/linux.h>

extern inline enum linux_error linux_madvise(linux_uword_t start, linux_size_t len_in, int behavior);
