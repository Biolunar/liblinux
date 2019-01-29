#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL4_RET(migrate_pages, linux_pid_t, pid, unsigned long, maxnode, unsigned long const*, old_nodes, unsigned long const*, new_nodes, int);
