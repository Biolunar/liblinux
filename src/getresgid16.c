#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(getresgid16, linux_old_gid_t*, rgidp, linux_old_gid_t*, egidp, linux_old_gid_t*, sgidp);
