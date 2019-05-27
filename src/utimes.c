#include <liblinux/linux.h>

extern inline enum linux_error linux_utimes(char* filename, struct linux_timeval* utimes);
