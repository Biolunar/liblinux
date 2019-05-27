#include <liblinux/linux.h>

extern inline enum linux_error linux_futex(uint32_t* uaddr, int op, uint32_t val, struct linux_kernel_timespec* utime, uint32_t* uaddr2, uint32_t val3, linux_word_t* result);
