#include <liblinux/linux.h>

extern inline linux_error_t linux_move_mount(linux_fd_t from_dfd, char const* from_path, linux_fd_t to_dfd, char const* to_path, unsigned int ms_flags);
