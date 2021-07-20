#include <liblinux/linux.h>

extern inline linux_error_t linux_request_key(char const* type, char const* description, char const* callout_info, linux_key_serial_t destringid, linux_word_t* result);
