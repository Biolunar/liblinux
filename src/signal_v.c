#include <liblinux/linux.h>

extern inline linux_error_t linux_signal_v(uint32_t sig, linux_sighandler_t handler, linux_uword_t* result);
