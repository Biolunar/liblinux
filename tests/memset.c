#include "memset.h"

void* memset(void* const dest, int const ch, size_t const count)
{
	for (size_t i = 0; i < count; ++i)
		*(unsigned char*)dest = (unsigned char)ch;
	return dest;
}
