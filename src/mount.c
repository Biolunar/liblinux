#include <liblinux/linux.h>

extern inline enum linux_error_t linux_mount(char* dev_name, char* dir_name, char* type, linux_uword_t flags, void* data);
