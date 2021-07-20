#include <liblinux/linux.h>

extern inline linux_error_t linux_add_key(char const* type, char const* description, void const* payload, linux_size_t plen, linux_key_serial_t ringid, linux_word_t* result);
