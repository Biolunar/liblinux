#include <liblinux/linux.h>

extern inline enum linux_error_t linux_fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int dfd, char const* pathname);
