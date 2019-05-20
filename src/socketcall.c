#include <liblinux/linux.h>

extern inline enum linux_error_t linux_socketcall(int call, linux_uword_t* args, int* result);
