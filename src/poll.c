#include <liblinux/linux.h>

extern inline enum linux_error linux_poll(struct linux_pollfd* ufds, unsigned int nfds, int timeout_msecs, int* result);
