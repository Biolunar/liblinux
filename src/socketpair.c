#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_NORET(socketpair, int, family, int, type, int, protocol, int*, usockvec);
