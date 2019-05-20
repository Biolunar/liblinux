#include <liblinux/linux.h>

extern inline enum linux_error_t linux_rt_sigpending(linux_sigset_t* uset, linux_size_t sigsetsize);
