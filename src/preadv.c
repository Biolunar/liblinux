#include <liblinux/linux.h>

extern inline enum linux_error linux_preadv(linux_uword_t fd, struct linux_iovec const* vec, linux_uword_t vlen, linux_uword_t pos_l, linux_uword_t pos_h, linux_ssize_t* result);
