#include <liblinux/linux.h>

extern inline enum linux_error linux_getgroups(int gidsetsize, linux_gid_t* grouplis, int* result);
