#include <liblinux/linux.h>

extern inline enum linux_error linux_poll(struct linux_pollfd* ufds, uint32_t nfds, int32_t timeout_msecs, uint32_t* result);
