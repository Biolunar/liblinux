#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_NORET(name_to_handle_at, int, dfd, char const*, name, struct linux_file_handle*, handle, int*, mnt_id, int, flag);
