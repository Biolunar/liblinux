#include <liblinux/linux.h>

extern inline enum linux_error linux_futimesat_time32(linux_fd_t dfd, char const* filename, struct linux_old_timeval32* t);
