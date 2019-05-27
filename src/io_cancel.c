#include <liblinux/linux.h>

extern inline enum linux_error linux_io_cancel(linux_aio_context_t ctx_id, struct linux_iocb* iocb, struct linux_io_event* result);
