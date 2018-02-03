#include "strlen.h"

size_t strlen(char const* str)
{
	size_t ret = 0;
	while (*str++)
		++ret;
	return ret;
}
