#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL3_NORET(mincore, unsigned long, start, linux_size_t, len, unsigned char*, vec);
