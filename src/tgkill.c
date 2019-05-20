#include <liblinux/linux.h>

extern inline enum linux_error_t linux_tgkill(linux_pid_t tgid, linux_pid_t pid, int sig);
