#include <string.h>

void *memset(void *s, int c, size_t n) {
	while(n > 0)
    ((char*) s)[n--] = c;

	return s;
}