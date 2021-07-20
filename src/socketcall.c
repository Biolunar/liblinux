#include <liblinux/linux.h>

extern inline linux_error_t linux_socketcall(int call, linux_uword_t* args, int* result);
