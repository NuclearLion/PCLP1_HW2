#include "array_op.h"

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
