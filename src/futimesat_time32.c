#include <liblinux/linux.h>

extern inline linux_error_t linux_futimesat_time32(linux_fd_t dfd, char const* filename, struct linux_timeval32* t);
