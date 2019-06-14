#include <liblinux/linux.h>

extern inline enum linux_error linux_socketpair(int family, int type, int protocol, linux_fd_t* usockvec);
