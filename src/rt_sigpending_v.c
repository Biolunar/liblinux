#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigpending_v(linux_sigset_t* uset, linux_size_t sigsetsize);
