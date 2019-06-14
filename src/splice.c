#include <liblinux/linux.h>

extern inline enum linux_error linux_splice(linux_fd_t fd_in, linux_loff_t* off_in, linux_fd_t fd_out, linux_loff_t* off_out, linux_size_t len, unsigned int flags, linux_word_t* result);
