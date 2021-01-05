#include <liblinux/linux.h>

extern inline enum linux_error linux_process_madvise(int const pidfd, struct linux_iovec const* const vec, linux_size_t const vlen, int const behavior, unsigned int const flags, linux_size_t* const result);
