#include <liblinux/linux.h>

extern inline linux_error_t linux_mq_open(char const* u_name, int oflag, linux_umode_t mode, struct linux_mq_attr* u_attr, int* result);
