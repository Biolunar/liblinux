#include <liblinux/linux.h>

extern inline linux_error_t linux_fanotify_mark(linux_fd_t fanotify_fd, unsigned int flags, uint64_t mask, linux_fd_t dfd, char const* pathname);
