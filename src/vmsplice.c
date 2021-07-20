#include <liblinux/linux.h>

extern inline linux_error_t linux_vmsplice(linux_fd_t fd, struct linux_iovec const* uiov, linux_uword_t nr_segs, unsigned int flags, linux_word_t* result);
