#include <liblinux/linux.h>

extern inline enum linux_error linux_io_pgetevents_v(linux_aio_context_t ctx_id, linux_word_t min_nr, linux_word_t nr, struct linux_io_event* events, struct linux_timespec* timeout, struct linux_aio_sigset const* usig, linux_word_t* result);
