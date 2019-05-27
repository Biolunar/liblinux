#include <liblinux/linux.h>

extern inline enum linux_error linux_select(int n, linux_fd_set* inp, linux_fd_set* outp, linux_fd_set* exp, struct linux_timeval* tvp, int* result);
