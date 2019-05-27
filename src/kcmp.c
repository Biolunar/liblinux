#include <liblinux/linux.h>

extern inline enum linux_error linux_kcmp(linux_pid_t pid1, linux_pid_t pid2, int type, linux_uword_t idx1, linux_uword_t idx2, int* result);
