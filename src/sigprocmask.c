#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sigprocmask(int how, linux_old_sigset_t* nset, linux_old_sigset_t* oset);
