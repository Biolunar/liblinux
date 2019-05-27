#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigsuspend(linux_sigset_t* unewset, linux_size_t sigsetsize);
