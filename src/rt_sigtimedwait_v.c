#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigtimedwait_v(linux_sigset_t const* uthese, linux_siginfo_t* uinfo, struct linux_timespec const* uts, linux_size_t sigsetsize, uint32_t* result);
