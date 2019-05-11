#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(io_pgetevents, linux_aio_context_t, ctx_id, linux_word_t, min_nr, linux_word_t, nr, struct linux_io_event*, events, struct linux_kernel_timespec*, timeout, struct linux_aio_sigset const*, usig, linux_word_t);
