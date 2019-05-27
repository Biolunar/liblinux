#include <liblinux/linux.h>

extern inline enum linux_error linux_linkat(int olddfd, char const* oldname, int newdfd, char const* newname, int flags);
