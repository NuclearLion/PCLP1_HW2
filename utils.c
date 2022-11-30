#include "utils.h"

void swap_charact(charact *a, charact *b) {
	charact tmp = *a;
	*a = *b;
	*b = tmp;
}