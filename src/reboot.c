#include <liblinux/linux.h>

extern inline linux_error_t linux_reboot(int magic1, int magic2, unsigned int cmd, void* arg);
