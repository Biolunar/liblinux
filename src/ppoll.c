#include <liblinux/linux.h>

extern inline enum linux_error linux_ppoll(struct linux_pollfd* ufds, unsigned int nfds, struct linux_timespec* tsp, linux_sigset_t const* sigmask, linux_size_t sigsetsize, int* result);
