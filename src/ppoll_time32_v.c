#include <liblinux/linux.h>

extern inline linux_error_t linux_ppoll_time32_v(struct linux_pollfd* ufds, uint32_t nfds, struct linux_timespec32* tsp, linux_sigset_t const* sigmask, linux_size_t sigsetsize, uint32_t* result);
