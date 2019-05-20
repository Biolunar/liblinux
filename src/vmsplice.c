#include <liblinux/linux.h>

extern inline enum linux_error_t linux_vmsplice(int fd, struct linux_iovec const* uiov, linux_uword_t nr_segs, unsigned int flags, linux_word_t* result);
