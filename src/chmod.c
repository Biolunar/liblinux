#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(chmod, char const*, filename, linux_umode_t, mode);
