#include <liblinux/linux.h>

extern inline enum linux_error linux_tgkill(linux_pid_t tgid, linux_pid_t pid, uint32_t sig);
