#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_pwait(linux_fd_t epfd, struct linux_epoll_event* events, int maxevents, int timeout, linux_sigset_t const* sigmask, linux_size_t sigsetsize, int* result);
