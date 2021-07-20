#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigaction_v(uint32_t sig, struct linux_sigaction const* act, struct linux_sigaction* oact, linux_size_t sigsetsize);
