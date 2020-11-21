#include <liblinux/linux.h>

extern inline enum linux_error linux_mq_timedsend(linux_mqd_t mqdes, char const* u_msg_ptr, linux_size_t msg_len, unsigned int msg_prio, struct linux_timespec const* u_abs_timeout);
