#include <liblinux/linux.h>

extern inline linux_error_t linux_execve(char const* filename, char const* const* argv, char const* const* envp);
