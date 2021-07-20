#include <liblinux/linux.h>

extern inline linux_error_t linux_landlock_restrict_self(linux_fd_t const ruleset_fd, uint32_t const flags);
