#include <liblinux/linux.h>

extern inline enum linux_error_t linux_ioperm(linux_uword_t from, linux_uword_t num, int turn_on);
