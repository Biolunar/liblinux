#include <liblinux/linux.h>

extern inline enum linux_error linux_openat2(linux_fd_t dfd, char const* filename, struct linux_open_how* how, linux_size_t usize, linux_fd_t* result);
