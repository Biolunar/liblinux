#include <liblinux/linux.h>

extern inline linux_error_t linux_getgroups16(int gidsetsize, linux_old_gid_t* grouplist, int* result);
