#include <liblinux/linux.h>

extern inline linux_error_t linux_adjtimex_time32(struct linux_timex32* utp, int* result);
