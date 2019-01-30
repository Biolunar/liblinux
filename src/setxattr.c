#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(setxattr, char const*, pathname, char const*, name, void const*, value, linux_size_t, size, int, flags);
