#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigqueueinfo(linux_pid_t pid, uint32_t sig, linux_siginfo_t* uinfo);
