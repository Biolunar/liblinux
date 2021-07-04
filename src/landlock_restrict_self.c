#include <liblinux/linux.h>

extern inline enum linux_error linux_landlock_restrict_self(linux_fd_t const ruleset_fd, uint32_t const flags);
