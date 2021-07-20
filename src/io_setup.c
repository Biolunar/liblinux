#include <liblinux/linux.h>

extern inline linux_error_t linux_io_setup(unsigned int nr_events, linux_aio_context_t* ctxp);
