#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(remap_file_pages, linux_uword_t, start, linux_uword_t, size, linux_uword_t, prot, linux_uword_t, pgoff, linux_uword_t, flags);
