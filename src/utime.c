#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(utime, char*, filename, struct linux_utimbuf*, times);
