#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL2_NORET(mq_notify, linux_mqd_t, mqdes, struct linux_sigevent const*, u_notification);
