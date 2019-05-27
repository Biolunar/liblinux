#include <liblinux/linux.h>

extern inline enum linux_error linux_lookup_dcookie(uint64_t cookie64, char* buf, linux_size_t len, int* result);
