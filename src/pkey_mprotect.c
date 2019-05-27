#include <liblinux/linux.h>

extern inline enum linux_error linux_pkey_mprotect(linux_uword_t start, linux_size_t len, linux_uword_t prot, int pkey);
