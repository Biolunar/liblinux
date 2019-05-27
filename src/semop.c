#include <liblinux/linux.h>

extern inline enum linux_error linux_semop(int semid, struct linux_sembuf* tsops, unsigned int nsops);
