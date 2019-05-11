#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(utime32, char const*, filename, struct linux_old_utimbuf32*, t);
