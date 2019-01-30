#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getresgid, linux_gid_t*, rgidp, linux_gid_t*, egidp, linux_gid_t*, sgidp);
