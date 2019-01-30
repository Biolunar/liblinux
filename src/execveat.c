#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(execveat, int, fd, char const*, filename, char const* const*, argv, char const* const*, envp, int, flags);
