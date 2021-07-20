#include <liblinux/linux.h>

extern inline linux_error_t linux_semtimedop(int semid, struct linux_sembuf* tsops, unsigned int nsops, struct linux_timespec const* timeout);
