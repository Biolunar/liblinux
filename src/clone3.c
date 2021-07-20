#include <liblinux/linux.h>

extern inline linux_error_t linux_clone3(struct linux_clone_args* uargs, linux_size_t size, linux_pid_t* result);
