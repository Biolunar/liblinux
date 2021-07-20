#include <liblinux/linux.h>

extern inline linux_error_t linux_fcntl(linux_fd_t fd, unsigned int cmd, linux_uword_t arg, linux_word_t* result);
