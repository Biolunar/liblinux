#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_tgsigqueueinfo_v(linux_pid_t tgid, linux_pid_t pid, uint32_t sig, linux_siginfo_t* uinfo);
