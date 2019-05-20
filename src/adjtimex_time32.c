#include <liblinux/linux.h>

extern inline enum linux_error_t linux_adjtimex_time32(struct linux_old_timex32* utp, int* result);
