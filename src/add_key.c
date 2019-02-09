#include <liblinux/linux.h>

extern inline LINUX_DECLARE_SYSCALL5_RET(add_key, char const*, type, char const*, description, void const*, payload, linux_size_t, plen, linux_key_serial_t, ringid, linux_word_t);
