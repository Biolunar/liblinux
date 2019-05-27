#include <liblinux/linux.h>

extern inline enum linux_error linux_capget(linux_cap_user_header_t header, struct linux_user_cap_data_struct* dataptr);
