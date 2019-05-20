#include <liblinux/linux.h>

extern inline enum linux_error_t linux_signalfd4(int ufd, linux_sigset_t* user_mask, linux_size_t sizemask, int flags, int* result);
