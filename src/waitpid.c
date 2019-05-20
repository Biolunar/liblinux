#include <liblinux/linux.h>

extern inline enum linux_error_t linux_waitpid(linux_pid_t pid, int* stat_addr, int options, linux_word_t* result);
