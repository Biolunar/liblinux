#include <liblinux/linux.h>

extern inline enum linux_error linux_ipc(unsigned int call, int first, linux_uword_t second, linux_uword_t third, void* ptr, linux_word_t fifth, linux_word_t* result);
