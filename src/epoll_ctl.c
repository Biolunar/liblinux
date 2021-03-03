#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_ctl(linux_fd_t epfd, uint32_t op, linux_fd_t fd, struct linux_epoll_event const* event);
