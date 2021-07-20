#include <liblinux/linux.h>

extern inline linux_error_t linux_remap_file_pages(linux_uword_t start, linux_uword_t size, linux_uword_t prot, linux_uword_t pgoff, linux_uword_t flags);
