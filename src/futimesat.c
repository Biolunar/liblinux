#include <liblinux/linux.h>

extern inline linux_error_t linux_futimesat(linux_fd_t dfd, char const* filename, struct linux_old_timeval* utimes);
