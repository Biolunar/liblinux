#include <liblinux/linux.h>

extern inline linux_error_t linux_move_pages(linux_pid_t pid, linux_uword_t nr_pages, void const** pages, int const* nodes, int* status, int flags);
