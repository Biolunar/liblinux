#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(setdomainname, char*, name, int, len);
