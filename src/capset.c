#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL2_NORET(capset, linux_cap_user_header_t, header, const linux_cap_user_data_t, data);
