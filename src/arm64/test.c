#include <stdint.h>

uint64_t linux_syscall3(uint64_t, uint64_t, uint64_t, uint64_t);

uint64_t sum(uint64_t x1, uint64_t x2, uint64_t x3, uint64_t x4, uint64_t x5, uint64_t x6, uint64_t x7)
{
	return x1 + x2 + x3 + x4 + x5 + x6 + x7;
}

int main(void)
{
	uint64_t x1 = 1;
	uint64_t x2 = 2;
	uint64_t x3 = 3;
	uint64_t x4 = 4;
	uint64_t x5 = 5;
	uint64_t x6 = 6;
	uint64_t x7 = 7;
	uint64_t result = sum(x1, x2, x3, x4, x5, x6, x7);
	uint64_t s = linux_syscall3(1, (uint64_t)"hi\n", 3, 64);
	return (int)s;
}
