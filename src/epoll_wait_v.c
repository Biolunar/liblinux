#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_wait_v(linux_fd_t epfd, struct linux_epoll_event* events, uint32_t maxevents, int32_t timeout, uint32_t* result);
