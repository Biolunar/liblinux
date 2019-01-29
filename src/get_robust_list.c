#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(get_robust_list, int, pid, struct linux_robust_list_head**, head_ptr, linux_size_t*, len_ptr);
