#include <liblinux/linux.h>

extern inline enum linux_error_t linux_mq_timedsend_time32(linux_mqd_t mqdes, char const* u_msg_ptr, unsigned int msg_len, unsigned int msg_prio, struct linux_old_timespec32 const* u_abs_timeout);
