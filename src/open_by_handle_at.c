#include <liblinux/linux.h>

extern inline enum linux_error linux_open_by_handle_at(int mountdirfd, struct linux_file_handle* handle, int flags, linux_word_t* result);
