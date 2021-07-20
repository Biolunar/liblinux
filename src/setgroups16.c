#include <liblinux/linux.h>

extern inline linux_error_t linux_setgroups16(int gidsetsize, linux_old_gid_t* grouplist);
