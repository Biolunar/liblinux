#include <liblinux/linux.h>

extern inline enum linux_error linux_epoll_pwait2(linux_fd_t epfd, struct linux_epoll_event* events, uint32_t maxevents, struct linux_timespec const* timeout, linux_sigset_t const* sigmask, linux_size_t sigsetsize, uint32_t* result);
