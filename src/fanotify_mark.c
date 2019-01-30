#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(fanotify_mark, int, fanotify_fd, unsigned int, flags, uint64_t, mask, int, dfd, char const*, pathname);
