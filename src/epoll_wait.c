#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_wait(linux_fd_t epfd, struct linux_epoll_event* events, int maxevents, int timeout, int* result);
