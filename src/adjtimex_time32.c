#include <liblinux/linux.h>

extern inline enum linux_error linux_adjtimex_time32(struct linux_timex32* utp, int* result);
