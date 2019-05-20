#include <liblinux/linux.h>

extern inline enum linux_error_t linux_socketpair(int family, int type, int protocol, int* usockvec);
