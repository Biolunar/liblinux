#include <liblinux/linux.h>

extern inline linux_error_t linux_sched_getaffinity(linux_pid_t pid, unsigned int len, linux_uword_t* user_mask_ptr);
