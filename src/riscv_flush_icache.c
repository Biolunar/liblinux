#include <liblinux/linux.h>

extern inline enum linux_error linux_riscv_flush_icache(uintptr_t const start, uintptr_t const end, uintptr_t const flags);
