#include <liblinux/linux.h>

extern inline linux_error_t linux_io_cancel(linux_aio_context_t ctx_id, struct linux_iocb* iocb, struct linux_io_event* result);
