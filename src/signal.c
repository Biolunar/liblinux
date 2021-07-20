#include <liblinux/linux.h>

extern inline linux_error_t linux_signal(uint32_t sig, linux_sighandler_t handler, linux_uword_t* result);
