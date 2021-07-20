#include <liblinux/linux.h>

extern inline linux_error_t linux_open_by_handle_at(int mountdirfd, struct linux_file_handle* handle, int flags, linux_word_t* result);
