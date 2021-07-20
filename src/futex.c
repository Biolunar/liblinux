#include <liblinux/linux.h>

extern inline linux_error_t linux_futex(uint32_t* uaddr, int op, uint32_t val, struct linux_timespec* utime, uint32_t* uaddr2, uint32_t val3, linux_word_t* result);
