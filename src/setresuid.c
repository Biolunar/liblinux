#include <liblinux/linux.h>

extern inline linux_error_t linux_setresuid(linux_uid_t ruid, linux_uid_t euid, linux_uid_t suid);
