#include <liblinux/linux.h>

extern inline enum linux_error_t linux_bpf(int cmd, union linux_bpf_attr* uattr, unsigned int size, int* result);
