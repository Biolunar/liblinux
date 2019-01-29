#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(mount, char*, dev_name, char*, dir_name, char*, type, unsigned long, flags, void*, data);
