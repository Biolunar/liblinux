#include <liblinux/linux.h>

extern inline enum linux_error_t linux_adjtimex(struct linux_kernel_timex* txc_p, int* result);
