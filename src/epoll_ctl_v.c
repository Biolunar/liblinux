#include <liblinux/linux.h>

extern inline linux_error_t linux_epoll_ctl_v(linux_fd_t epfd, uint32_t op, linux_fd_t fd, struct linux_epoll_event const* event);
