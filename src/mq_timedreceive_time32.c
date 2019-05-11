#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(mq_timedreceive_time32, linux_mqd_t, mqdes, char*, u_msg_ptr, unsigned int, msg_len, unsigned int*, u_msg_prio, struct linux_old_timespec32 const*, u_abs_timeout, int);
