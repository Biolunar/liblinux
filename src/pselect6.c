#include <liblinux/linux.h>

extern inline enum linux_error linux_pselect6(int n, linux_fd_set* inp, linux_fd_set* outp, linux_fd_set* exp, struct linux_kernel_timespec* tsp, void* sig, linux_word_t* result);
