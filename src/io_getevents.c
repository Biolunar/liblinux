#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_RET(io_getevents, linux_aio_context_t, ctx_id, long, min_nr, long, nr, struct linux_io_event*, events, struct linux_timespec*, timeout, long);
