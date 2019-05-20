#include <liblinux/linux.h>

extern inline enum linux_error_t linux_getrusage(int who, struct linux_rusage* ru);
