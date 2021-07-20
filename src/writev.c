#include <liblinux/linux.h>

extern inline linux_error_t linux_writev(linux_uword_t fd, struct linux_iovec const* vec, linux_uword_t vlen, linux_ssize_t* result);
