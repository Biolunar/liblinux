#include <liblinux/linux.h>

extern inline enum linux_error linux_inotify_add_watch(int fd, char const* pathname, uint32_t mask, int* result);
