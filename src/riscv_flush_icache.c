#include <liblinux/linux.h>

extern inline linux_error_t linux_riscv_flush_icache(uintptr_t const start, uintptr_t const end, uintptr_t const flags);
