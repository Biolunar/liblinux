#include <liblinux/linux.h>

extern inline enum linux_error linux_renameat2(int olddfd, char const* oldname, int newdfd, char const* newname, unsigned int flags);
