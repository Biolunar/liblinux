#include <liblinux/linux.h>

extern inline enum linux_error_t linux_readv(linux_uword_t fd, struct linux_iovec const* vec, linux_uword_t vlen, linux_ssize_t* result);
