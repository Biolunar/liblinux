#include <liblinux/linux.h>

extern inline linux_error_t linux_wait4(linux_pid_t upid, int* stat_addr, int options, struct linux_rusage* ru, linux_word_t* result);
