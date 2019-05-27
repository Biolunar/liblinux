#include <liblinux/linux.h>

extern inline enum linux_error linux_statx(int dfd, char const* filename, unsigned int flags, unsigned int mask, struct linux_statx* buffer);
