#include <liblinux/linux.h>

extern inline enum linux_error_t linux_epoll_wait(int epfd, struct linux_epoll_event* events, int maxevents, int timeout, int* result);
