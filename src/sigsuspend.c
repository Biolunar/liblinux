#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sigsuspend(int unused1, int unused2, linux_old_sigset_t mask);
