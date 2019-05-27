#include <liblinux/linux.h>

extern inline enum linux_error linux_wait4(linux_pid_t upid, int* stat_addr, int options, struct linux_rusage* ru, linux_word_t* result);
