#include <liblinux/linux.h>

extern inline enum linux_error_t linux_semtimedop(int semid, struct linux_sembuf* tsops, unsigned int nsops, struct linux_kernel_timespec const* timeout);
