#include <liblinux/linux.h>

extern inline linux_error_t linux_socketpair(int family, int type, int protocol, linux_fd_t* usockvec);
