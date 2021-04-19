#include <liblinux/linux.h>

extern inline enum linux_error linux_pselect6(uint32_t n, linux_fd_set* inp, linux_fd_set* outp, linux_fd_set* exp, struct linux_timespec* tsp, void* sig, uint32_t* result);
