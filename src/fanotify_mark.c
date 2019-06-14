#include <liblinux/linux.h>

extern inline enum linux_error linux_fanotify_mark(linux_fd_t fanotify_fd, unsigned int flags, uint64_t mask, linux_fd_t dfd, char const* pathname);
