#include <liblinux/linux.h>

extern inline enum linux_error linux_semtimedop_time32(int semid, struct linux_sembuf* tsems, unsigned int nsops, struct linux_old_timespec32 const* timeout);
