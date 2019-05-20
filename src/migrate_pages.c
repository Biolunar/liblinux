#include <liblinux/linux.h>

extern inline enum linux_error_t linux_migrate_pages(linux_pid_t pid, linux_uword_t maxnode, linux_uword_t const* old_nodes, linux_uword_t const* new_nodes, int* result);
