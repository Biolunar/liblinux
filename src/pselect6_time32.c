#include <liblinux/linux.h>

extern inline enum linux_error_t linux_pselect6_time32(int n, linux_fd_set* inp, linux_fd_set* outp, linux_fd_set* exp, struct linux_old_timespec32* tsp, void* sig, linux_word_t* result);
