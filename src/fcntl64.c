#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fcntl64(unsigned int fd, unsigned int cmd, linux_uword_t arg, linux_word_t* result);
