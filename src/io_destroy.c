#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(io_destroy, linux_aio_context_t, ctx);
