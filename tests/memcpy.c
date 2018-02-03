#include "memcpy.h"

void* memcpy(void* const dest, void const* const src, size_t count)
{
	unsigned char* d = dest;
	unsigned char const* s = src;
	while (count--)
	{
		*d++ = *s;
		++s;
	}
	return dest;
}
