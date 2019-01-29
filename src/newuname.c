#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL1_NORET(newuname, struct linux_new_utsname*, name);
