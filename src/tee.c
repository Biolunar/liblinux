#include <liblinux/linux.h>

extern inline enum linux_error_t linux_tee(int fdin, int fdout, linux_size_t len, unsigned int flags, int* result);
