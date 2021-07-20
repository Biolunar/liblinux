#include <liblinux/linux.h>

extern inline linux_error_t linux_pivot_root(char const* new_root, char const* put_old);
