#include <liblinux/linux.h>

extern inline enum linux_error_t linux_futimesat(int dfd, char const* filename, struct linux_timeval* utimes);
