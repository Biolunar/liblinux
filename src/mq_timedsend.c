#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL5_NORET(mq_timedsend, linux_mqd_t, mqdes, char const*, u_msg_ptr, linux_size_t, msg_len, unsigned int, msg_prio, struct linux_kernel_timespec const*, u_abs_timeout);
