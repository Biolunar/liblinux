#include <liblinux/linux.h>

extern inline linux_error_t linux_mmap_pgoff(linux_uword_t addr, linux_uword_t len, linux_uword_t prot, linux_uword_t flags, linux_uword_t fd, linux_uword_t pgoff, linux_uword_t* result);
