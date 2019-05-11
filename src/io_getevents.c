#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(io_getevents, linux_aio_context_t, ctx_id, linux_word_t, min_nr, linux_word_t, nr, struct linux_io_event*, events, struct linux_kernel_timespec*, timeout, int);
