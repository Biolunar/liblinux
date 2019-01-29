#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(io_submit, linux_aio_context_t, ctx_id, long, nr, struct linux_iocb**, iocbpp, long);
