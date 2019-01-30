#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(io_setup, unsigned int, nr_events, linux_aio_context_t*, ctxp);
