#include <liblinux/linux.h>

extern inline enum linux_error_t linux_getsid(linux_pid_t pid, int* result);
