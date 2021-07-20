#include <liblinux/linux.h>

extern inline linux_error_t linux_io_getevents(linux_aio_context_t ctx_id, linux_word_t min_nr, linux_word_t nr, struct linux_io_event* events, struct linux_timespec* timeout, int* result);
