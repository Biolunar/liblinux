#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigprocmask_v(uint32_t how, linux_sigset_t* nset, linux_sigset_t* oset, linux_size_t sigsetsize);
