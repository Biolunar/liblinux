#include <liblinux/linux.h>

extern inline linux_error_t linux_execveat(linux_fd_t fd, char const* filename, char const* const* argv, char const* const* envp, int flags);
