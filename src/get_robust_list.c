#include <liblinux/linux.h>

extern inline enum linux_error_t linux_get_robust_list(int pid, struct linux_robust_list_head** head_ptr, linux_size_t* len_ptr);
