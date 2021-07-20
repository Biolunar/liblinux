#include <liblinux/linux.h>

extern inline linux_error_t linux_io_submit_v(linux_aio_context_t ctx_id, linux_word_t nr, struct linux_iocb** iocbpp, linux_word_t* result);
