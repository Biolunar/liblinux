#include <liblinux/linux.h>

extern inline linux_error_t linux_mq_notify(linux_mqd_t mqdes, struct linux_sigevent const* u_notification);
