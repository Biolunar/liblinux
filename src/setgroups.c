#include <liblinux/linux.h>

extern inline linux_error_t linux_setgroups(int gidsetsize, linux_gid_t* grouplist);
