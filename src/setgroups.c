#include <liblinux/linux.h>

extern inline enum linux_error linux_setgroups(int gidsetsize, linux_gid_t* grouplist);
