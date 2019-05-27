#include <liblinux/linux.h>

extern inline enum linux_error linux_kexec_load(linux_uword_t entry, linux_uword_t nr_segments, struct linux_kexec_segment* segments, linux_uword_t flags);
