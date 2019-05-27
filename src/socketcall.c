#include <liblinux/linux.h>

extern inline enum linux_error linux_socketcall(int call, linux_uword_t* args, int* result);
