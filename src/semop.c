#include <liblinux/linux.h>

extern inline linux_error_t linux_semop(int semid, struct linux_sembuf* tsops, unsigned int nsops);
