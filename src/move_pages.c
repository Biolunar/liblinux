#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL6_NORET(move_pages, linux_pid_t, pid, unsigned long, nr_pages, void const**, pages, int const*, nodes, int*, status, int, flags);
