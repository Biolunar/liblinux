#include <liblinux/linux.h>

extern inline linux_error_t linux_rt_sigtimedwait_time32_v(linux_sigset_t const* uthese, linux_siginfo_t* uinfo, struct linux_timespec32 const* uts, linux_size_t sigsetsize, uint32_t* result);
