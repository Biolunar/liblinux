#include <liblinux/linux.h>

extern inline linux_error_t linux_mq_getsetattr(linux_mqd_t mqdes, struct linux_mq_attr const* u_mqstat, struct linux_mq_attr* u_omqstat);
