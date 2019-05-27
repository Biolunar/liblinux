#include <liblinux/linux.h>

extern inline enum linux_error linux_getdents(unsigned int fd, struct linux_dirent* dirent, unsigned int count, int* result);
