#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(io_cancel, linux_aio_context_t, ctx_id, struct linux_iocb*, iocb, struct linux_io_event*, result);
