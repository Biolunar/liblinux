#include <liblinux/linux.h>

extern inline linux_error_t linux_landlock_add_rule(linux_fd_t const ruleset_fd, enum linux_landlock_rule_type const rule_type, void const* const rule_attr, uint32_t const flags);
