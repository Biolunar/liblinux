#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigpending_v(linux_sigset_t* uset, linux_size_t sigsetsize);
