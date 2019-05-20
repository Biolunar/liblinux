#include <liblinux/linux.h>

extern inline enum linux_error_t linux_rt_sigtimedwait_time32(linux_sigset_t const* uthese, linux_siginfo_t* uinfo, struct linux_old_timespec32 const* uts, linux_size_t sigsetsize, int* result);
