#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(execve, char const*, filename, char const* const*, argv, char const* const*, envp);
