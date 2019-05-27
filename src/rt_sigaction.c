#include <liblinux/linux.h>

extern inline enum linux_error linux_rt_sigaction(int sig, struct linux_sigaction const* act, struct linux_sigaction* oact, linux_size_t sigsetsize);
