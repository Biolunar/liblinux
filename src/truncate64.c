#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(truncate64, char const*, path, linux_loff_t, length);
