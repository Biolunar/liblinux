#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL4_RET(request_key, char const*, type, char const*, description, char const*, callout_info, linux_key_serial_t, destringid, long);
