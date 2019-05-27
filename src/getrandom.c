#include <liblinux/linux.h>

extern inline enum linux_error linux_getrandom(char* buf, linux_size_t count, unsigned int flags, linux_ssize_t* result);
