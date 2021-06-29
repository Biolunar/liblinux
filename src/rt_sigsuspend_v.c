#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigsuspend_v(linux_sigset_t* unewset, linux_size_t sigsetsize);
