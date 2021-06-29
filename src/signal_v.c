#include <liblinux/linux.h>

extern inline enum linux_error linux_signal_v(uint32_t sig, linux_sighandler_t handler, linux_uword_t* result);
