#include <liblinux/linux.h>

extern inline enum linux_error_t linux_rseq(struct linux_rseq* rseq, uint32_t rseq_len, int flags, uint32_t sig);
