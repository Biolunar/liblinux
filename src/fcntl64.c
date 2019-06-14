#include <liblinux/linux.h>

extern inline enum linux_error linux_fcntl64(linux_fd_t fd, unsigned int cmd, linux_uword_t arg, linux_word_t* result);
