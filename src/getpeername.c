#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getpeername, int, fd, struct linux_sockaddr*, usockaddr, int*, usockaddr_len);
