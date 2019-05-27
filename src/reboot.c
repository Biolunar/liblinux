#include <liblinux/linux.h>

extern inline enum linux_error linux_reboot(int magic1, int magic2, unsigned int cmd, void* arg);
