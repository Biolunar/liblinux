#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_RET(io_submit, linux_aio_context_t, ctx_id, linux_word_t, nr, struct linux_iocb**, iocbpp, linux_word_t);
