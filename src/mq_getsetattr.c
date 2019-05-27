#include <liblinux/linux.h>

extern inline enum linux_error linux_mq_getsetattr(linux_mqd_t mqdes, struct linux_mq_attr const* u_mqstat, struct linux_mq_attr* u_omqstat);
