#include <liblinux/linux.h>

extern inline linux_error_t linux_epoll_pwait(linux_fd_t epfd, struct linux_epoll_event* events, uint32_t maxevents, int32_t timeout, linux_sigset_t const* sigmask, linux_size_t sigsetsize, uint32_t* result);
