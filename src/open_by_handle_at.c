#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_RET(open_by_handle_at, int, mountdirfd, struct linux_file_handle*, handle, int, flags, long);
