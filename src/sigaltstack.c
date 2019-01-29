#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(sigaltstack, linux_stack_t const*, uss, linux_stack_t*, uoss);
