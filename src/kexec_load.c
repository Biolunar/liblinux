#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_NORET(kexec_load, unsigned long, entry, unsigned long, nr_segments, struct linux_kexec_segment*, segments, unsigned long, flags);
