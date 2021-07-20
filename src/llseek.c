#include <liblinux/linux.h>

extern inline linux_error_t linux_llseek(linux_fd_t fd, linux_uword_t offset_high, linux_uword_t offset_low, linux_loff_t* result, unsigned int whence);
