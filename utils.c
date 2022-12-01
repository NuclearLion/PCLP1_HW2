//Dan Dominic Staicu 311CA
#include "utils.h"

//swaps any kind of variables
void swap_any(void *a, void *b, size_t s)
{
    void *tmp = malloc(s);
    memcpy(tmp, a, s);
    memcpy(a, b, s);
    memcpy(b, tmp, s);
    free(tmp);
}

//read array dim and elements
void read_vect(int **v, int *n)
{
	scanf("%d", n);
	int *w = (int *)malloc(*n * sizeof(int));
	if (!w) {
		fprintf(stderr, "malloc failed in read_vect\n");
		*v = NULL;
		return;
	}
	*v = w;

	for (int i = 0; i < *n; ++i)
		scanf("%d", &w[i]);
}

