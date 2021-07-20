#include <liblinux/linux.h>

extern inline linux_error_t linux_select_v(uint32_t n, linux_fd_set* inp, linux_fd_set* outp, linux_fd_set* exp, struct linux_old_timeval* tvp, uint32_t* result);
