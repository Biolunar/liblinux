#include <liblinux/linux.h>

extern inline enum linux_error linux_renameat(int olddfd, char const* oldname, int newdfd, char const* newname);
