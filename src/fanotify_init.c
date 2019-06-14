#include <liblinux/linux.h>

extern inline enum linux_error linux_fanotify_init(unsigned int flags, unsigned int event_f_flags, linux_fd_t* result);
