#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(kexec_load, linux_uword_t, entry, linux_uword_t, nr_segments, struct linux_kexec_segment*, segments, linux_uword_t, flags);
