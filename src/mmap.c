#include <liblinux/linux.h>

extern inline enum linux_error linux_mmap(linux_uword_t addr, linux_uword_t len, linux_uword_t prot, linux_uword_t flags, linux_uword_t fd, linux_uword_t off, linux_uword_t* result);
