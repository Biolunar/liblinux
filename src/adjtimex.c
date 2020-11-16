#include <liblinux/linux.h>

extern inline enum linux_error linux_adjtimex(struct linux_timex* txc_p, int* result);
