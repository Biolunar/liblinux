#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(getrusage, int, who, struct linux_rusage*, ru);
