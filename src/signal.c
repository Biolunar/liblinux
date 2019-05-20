#include <liblinux/linux.h>

extern inline enum linux_error_t linux_signal(int sig, linux_sighandler_t handler, linux_uword_t* result);
