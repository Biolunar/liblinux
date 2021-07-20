#include <liblinux/linux.h>

extern inline linux_error_t linux_lookup_dcookie(uint64_t cookie64, char* buf, linux_size_t len, int* result);
