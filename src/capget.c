#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(capget, linux_cap_user_header_t, header, struct linux_user_cap_data_struct*, dataptr);
