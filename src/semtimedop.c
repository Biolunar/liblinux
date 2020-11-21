#include <liblinux/linux.h>

extern inline enum linux_error linux_semtimedop(int semid, struct linux_sembuf* tsops, unsigned int nsops, struct linux_timespec const* timeout);
