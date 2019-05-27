#include <liblinux/linux.h>

extern inline enum linux_error linux_mq_notify(linux_mqd_t mqdes, struct linux_sigevent const* u_notification);
