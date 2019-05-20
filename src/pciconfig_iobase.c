#include <liblinux/linux.h>

extern inline enum linux_error_t linux_pciconfig_iobase(linux_word_t which, linux_uword_t bus, linux_uword_t devfn, linux_word_t* result);
