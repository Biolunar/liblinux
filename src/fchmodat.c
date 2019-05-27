#include <liblinux/linux.h>

extern inline enum linux_error linux_fchmodat(int dfd, char const* filename, linux_umode_t mode);
