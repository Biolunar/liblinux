#include <liblinux/linux.h>

extern inline enum linux_error_t linux_sched_setaffinity(linux_pid_t pid, unsigned int len, linux_uword_t* user_mask_ptr);
