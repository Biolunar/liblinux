#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL1_NORET(set_thread_area, struct linux_user_desc*, u_info);
