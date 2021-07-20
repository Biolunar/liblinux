#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigprocmask(uint32_t how, linux_sigset_t* nset, linux_sigset_t* oset, linux_size_t sigsetsize);
