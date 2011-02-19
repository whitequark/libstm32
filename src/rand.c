unsigned __rand_seed;

unsigned rand() {
	unsigned hi, lo;

	hi = 16807 * (__rand_seed & 0xFFFF);
	lo = 16807 * (__rand_seed >> 16);

	lo += (hi & 0x7FFF) << 16;
	lo += hi >> 15;

	if(lo > 0x7FFFFFFF) lo -= 0x7FFFFFFF;

	return (__rand_seed = lo);
}

void srand(unsigned seed) {
	__rand_seed = seed;
}