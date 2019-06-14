#include <liblinux/linux.h>

extern inline enum linux_error linux_dup2(linux_fd_t oldfd, linux_fd_t newfd, int* result);
