#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(uname, struct linux_old_utsname*, name);
