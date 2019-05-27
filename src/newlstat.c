#include <liblinux/linux.h>

extern inline enum linux_error linux_newlstat(char const* filename, struct linux_stat* statbuf);
