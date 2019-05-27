#include <liblinux/linux.h>

extern inline enum linux_error linux_io_submit(linux_aio_context_t ctx_id, linux_word_t nr, struct linux_iocb** iocbpp, linux_word_t* result);
