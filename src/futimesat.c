#include <liblinux/linux.h>

extern inline enum linux_error linux_futimesat(linux_fd_t dfd, char const* filename, struct linux_timeval* utimes);
