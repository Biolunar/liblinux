#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(setsockopt, int, fd, int, level, int, optname, char*, optval, int, optlen);
