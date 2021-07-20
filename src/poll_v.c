#include <liblinux/linux.h>

extern inline linux_error_t linux_poll_v(struct linux_pollfd* ufds, uint32_t nfds, int32_t timeout_msecs, uint32_t* result);
