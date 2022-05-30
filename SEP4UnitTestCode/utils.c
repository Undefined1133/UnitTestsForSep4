#include "utils.h"
static int8_t _memory = 0;

void utils_initialise() {
	_memory = 0;
}

int8_t utils_add(int8_t n1, int8_t n2) {
	return n1 + n2;
}


void utils_storeValue(int8_t value) {
	_memory = value;
}

int8_t utils_restoreValue() {
	return _memory;
}