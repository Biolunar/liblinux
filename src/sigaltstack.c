#include <liblinux/linux.h>

extern inline linux_error_t linux_sigaltstack(linux_stack_t const* uss, linux_stack_t* uoss);
