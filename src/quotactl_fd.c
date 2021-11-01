#include <liblinux/linux.h>

extern inline linux_error_t linux_quotactl_fd(linux_fd_t fd, unsigned int cmd, linux_qid_t id, void* addr);
