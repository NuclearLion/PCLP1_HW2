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
	//if failed, assign NULL to *v vector
	if (!w) {
		fprintf(stderr, "malloc failed in read_vect\n");
		*v = NULL;
		return;
	}
	*v = w;

	//read elements of the array
	for (int i = 0; i < *n; ++i)
		scanf("%d", &w[i]);
}

//check if sum after % MOD is negative
//if it's negative, the value should be MOD + sum
int check_pos(int sum)
{
	if (sum < 0)
		sum += MOD;
	return sum;
}

//check if current index corresponds to any matrix
int check_error(int index, int c_ind, int mat_cnt)
{
	//if there are no mats in db and
	//if curent index is above the last index
	if (c_ind < 0 || c_ind > index || mat_cnt < 1) {
		printf("No matrix with the given index\n");
		return 1;
	}
	return 0;
}

//it's more efficient to create some local vars and read them with 2 fors
//rather than reading them as arrays (so we don't have to allocate memory)
void trash(void)
{
	int lin = 0, col = 0;
	int trash = 0;
	scanf("%d", &lin);
	for (int i = 0; i < lin; ++i)
		scanf("%d", &trash);
	scanf("%d", &col);
	for (int i = 0; i < col; ++i)
		scanf("%d", &trash);
}

//overwrite a value over another, regardless their data type
void overwrite(void *a, void *b, size_t s)
{
	memcpy(a, b, s);
}
