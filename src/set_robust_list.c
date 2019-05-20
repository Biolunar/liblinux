#include <liblinux/linux.h>

extern inline enum linux_error_t linux_set_robust_list(struct linux_robust_list_head* head, linux_size_t len);
