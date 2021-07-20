#include <liblinux/linux.h>

extern inline linux_error_t linux_sigprocmask(uint32_t how, linux_old_sigset_t* nset, linux_old_sigset_t* oset);
