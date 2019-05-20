#include <liblinux/linux.h>

extern inline enum linux_error_t linux_mincore(linux_uword_t start, linux_size_t len, unsigned char* vec);
