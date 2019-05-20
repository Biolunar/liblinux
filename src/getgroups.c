#include <liblinux/linux.h>

extern inline enum linux_error_t linux_getgroups(int gidsetsize, linux_gid_t* grouplis, int* result);
