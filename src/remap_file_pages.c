#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(remap_file_pages, unsigned long, start, unsigned long, size, unsigned long, prot, unsigned long, pgoff, unsigned long, flags);
