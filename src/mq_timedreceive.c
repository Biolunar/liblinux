#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(mq_timedreceive, linux_mqd_t, mqdes, char*, u_msg_ptr, linux_size_t, msg_len, unsigned int*, u_msg_prio, struct linux_kernel_timespec const*, u_abs_timeout, int);
