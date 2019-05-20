#include <liblinux/linux.h>

extern inline enum linux_error_t linux_symlinkat(char const* oldname, int newdfd, char const* newname);
