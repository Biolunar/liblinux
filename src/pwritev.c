#include <liblinux/linux.h>

extern inline linux_error_t linux_pwritev(linux_uword_t fd, struct linux_iovec const* vec, linux_uword_t vlen, linux_uword_t pos_l, linux_uword_t pos_h, linux_ssize_t* result);
