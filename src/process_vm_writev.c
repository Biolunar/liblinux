#include <liblinux/linux.h>

extern inline enum linux_error linux_process_vm_writev(linux_pid_t pid, struct linux_iovec const* lvec, linux_uword_t liovcnt, struct linux_iovec const* rvec, linux_uword_t riovcnt, linux_uword_t flags, linux_ssize_t* result);
