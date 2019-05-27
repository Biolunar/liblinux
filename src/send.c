#include <liblinux/linux.h>

extern inline enum linux_error linux_send(int fd, void* buff, linux_size_t len, unsigned int flags, int* result);
