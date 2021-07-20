#include <liblinux/linux.h>

extern inline linux_error_t linux_modify_ldt(int func, void* ptr, linux_uword_t bytecount, int* result);
