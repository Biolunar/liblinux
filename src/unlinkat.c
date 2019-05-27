#include <liblinux/linux.h>

extern inline enum linux_error linux_unlinkat(int dfd, char const* pathname, int flag);
