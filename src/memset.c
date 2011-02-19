#include <string.h>

void *memset(void *s, int c, size_t n) {
	for(int i = 0; i < n; i++) {
		((char*)s)[i] = c;
	}

	return s;
}