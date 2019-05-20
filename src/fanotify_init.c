#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fanotify_init(unsigned int flags, unsigned int event_f_flags, int* result);
