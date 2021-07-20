#include <liblinux/linux.h>

extern inline linux_error_t linux_getgroups(int gidsetsize, linux_gid_t* grouplis, int* result);
