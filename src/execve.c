#include <liblinux/linux.h>

extern inline enum linux_error linux_execve(char const* filename, char const* const* argv, char const* const* envp);
