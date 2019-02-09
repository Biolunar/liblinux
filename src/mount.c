#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(mount, char*, dev_name, char*, dir_name, char*, type, linux_uword_t, flags, void*, data);
