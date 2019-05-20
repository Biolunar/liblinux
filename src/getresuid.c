#include <liblinux/linux.h>

extern inline enum linux_error_t linux_getresuid(linux_uid_t* ruidp, linux_uid_t* euidp, linux_uid_t* suidp);
