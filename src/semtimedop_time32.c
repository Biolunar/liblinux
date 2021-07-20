#include <liblinux/linux.h>

extern inline linux_error_t linux_semtimedop_time32(int semid, struct linux_sembuf* tsems, unsigned int nsops, struct linux_timespec32 const* timeout);
