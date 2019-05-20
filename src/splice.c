#include <liblinux/linux.h>

extern inline enum linux_error_t linux_splice(int fd_in, linux_loff_t* off_in, int fd_out, linux_loff_t* off_out, linux_size_t len, unsigned int flags, linux_word_t* result);
