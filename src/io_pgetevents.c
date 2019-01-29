#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_RET(io_pgetevents, linux_aio_context_t, ctx_id, long, min_nr, long, nr, struct linux_io_event*, events, struct linux_timespec*, timeout, struct linux_aio_sigset const*, usig, long);
