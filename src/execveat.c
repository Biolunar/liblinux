#include <liblinux/linux.h>

extern inline enum linux_error_t linux_execveat(int fd, char const* filename, char const* const* argv, char const* const* envp, int flags);
