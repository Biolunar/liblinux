#include <liblinux/linux.h>

extern inline enum linux_error_t linux_faccessat(int dfd, char const* filename, int mode);
