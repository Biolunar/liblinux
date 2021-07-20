#include <liblinux/linux.h>

extern inline linux_error_t linux_sigaction_v(uint32_t sig, struct linux_old_sigaction const* act, struct linux_old_sigaction* oact);
