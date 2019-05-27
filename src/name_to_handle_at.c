#include <liblinux/linux.h>

extern inline enum linux_error linux_name_to_handle_at(int dfd, char const* name, struct linux_file_handle* handle, int* mnt_id, int flag);
