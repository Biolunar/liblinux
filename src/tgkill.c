#include <liblinux/linux.h>

extern inline linux_error_t linux_tgkill(linux_pid_t tgid, linux_pid_t pid, uint32_t sig);
