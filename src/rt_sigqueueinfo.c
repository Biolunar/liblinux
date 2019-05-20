#include <liblinux/linux.h>

extern inline enum linux_error_t linux_rt_sigqueueinfo(linux_pid_t pid, int sig, linux_siginfo_t* uinfo);
