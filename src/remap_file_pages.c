#include <liblinux/linux.h>

extern inline enum linux_error linux_remap_file_pages(linux_uword_t start, linux_uword_t size, linux_uword_t prot, linux_uword_t pgoff, linux_uword_t flags);
