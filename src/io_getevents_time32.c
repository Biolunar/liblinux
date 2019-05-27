#include <liblinux/linux.h>

extern inline enum linux_error linux_io_getevents_time32(uint32_t ctx_id, int32_t min_nr, int32_t nr, struct linux_io_event* events, struct linux_old_timespec32* timeout, int* result);
