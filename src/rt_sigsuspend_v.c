#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigsuspend_v(linux_sigset_t* unewset, linux_size_t sigsetsize);
