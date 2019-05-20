#include <liblinux/linux.h>

extern inline enum linux_error_t linux_quotactl(unsigned int cmd, char const* special, linux_qid_t id, void* addr);
