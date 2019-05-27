#include <liblinux/linux.h>

extern inline enum linux_error linux_sigaction(int sig, struct linux_old_sigaction const* act, struct linux_old_sigaction* oact);
