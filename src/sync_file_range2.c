#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(sync_file_range2, int, fd, unsigned int, flags, linux_loff_t, offset, linux_loff_t, nbytes);
