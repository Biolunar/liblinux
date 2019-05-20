#include <liblinux/linux.h>

extern inline enum linux_error_t linux_set_tid_address(int* tidptr, linux_pid_t* result);
