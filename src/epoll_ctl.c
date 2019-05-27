#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_ctl(int epfd, int op, int fd, struct linux_epoll_event* event);
