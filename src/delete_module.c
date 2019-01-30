#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(delete_module, char const*, name_user, unsigned int, flags);
