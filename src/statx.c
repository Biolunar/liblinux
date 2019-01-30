#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(statx, int, dfd, char const*, filename, unsigned, flags, unsigned int, mask, struct linux_statx*, buffer);
