#include <liblinux/linux.h>

extern inline enum linux_error linux_syslog(int type, char* buf, int len, int* result);
