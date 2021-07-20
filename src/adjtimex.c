#include <liblinux/linux.h>

extern inline linux_error_t linux_adjtimex(struct linux_timex* txc_p, int* result);
