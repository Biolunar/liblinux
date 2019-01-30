#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(sethostname, char*, name, int, len);
