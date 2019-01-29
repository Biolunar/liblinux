#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(set_robust_list, struct linux_robust_list_head*, head, linux_size_t, len);
