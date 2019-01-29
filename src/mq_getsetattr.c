#include "linux.h"

extern inline LINUX_DECLARE_SYSCALL3_NORET(mq_getsetattr, linux_mqd_t, mqdes, struct linux_mq_attr const*, u_mqstat, struct linux_mq_attr*, u_omqstat);
