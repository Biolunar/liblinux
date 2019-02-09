#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(clone, linux_uword_t, clone_flags, linux_uword_t, newsp, int*, parent_tidptr, int*, child_tidptr, linux_uword_t, tls, linux_word_t);
