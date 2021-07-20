#include <liblinux/linux.h>

extern inline linux_error_t linux_landlock_create_ruleset(struct linux_landlock_ruleset_attr const* const attr, linux_size_t const size, uint32_t const flags, int* result);
