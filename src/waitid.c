#include <liblinux/linux.h>

extern inline enum linux_error linux_waitid(int which, linux_pid_t upid, struct linux_siginfo* infop, int options, struct linux_rusage* ru);
