#include <liblinux/linux.h>

extern inline linux_error_t linux_capget(linux_cap_user_header_t header, struct linux_user_cap_data_struct* dataptr);
