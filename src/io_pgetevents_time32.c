#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL6_RET(io_pgetevents_time32, linux_aio_context_t, ctx_id, linux_word_t, min_nr, linux_word_t, nr, struct linux_io_event*, events, struct linux_old_timespec32*, timeout, struct linux_aio_sigset const*, usig, int);
