#include <liblinux/linux.h>

extern inline enum linux_error linux_execveat(linux_fd_t fd, char const* filename, char const* const* argv, char const* const* envp, int flags);
