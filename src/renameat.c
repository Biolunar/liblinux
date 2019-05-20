#include <liblinux/linux.h>

extern inline enum linux_error_t linux_renameat(int olddfd, char const* oldname, int newdfd, char const* newname);
