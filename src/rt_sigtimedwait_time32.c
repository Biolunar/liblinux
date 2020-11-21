#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigtimedwait_time32(linux_sigset_t const* uthese, linux_siginfo_t* uinfo, struct linux_timespec32 const* uts, linux_size_t sigsetsize, int* result);
