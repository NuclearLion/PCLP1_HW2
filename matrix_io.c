#include "matrix_io.h"

//alloc matrix
int **alloc_matrix(int n, int m)
{
	int **tmp_mat = (int **)malloc(n * sizeof(int *));
	if (!tmp_mat) {
		fprintf(stderr, "malloc failed\n");
		return NULL;
	}
	for (int i = 0; i < n; ++i) {
		tmp_mat[i] = (int *)malloc(m * sizeof(int));
		if (!tmp_mat[i]) {
			fprintf(stderr, "malloc failed\n");
			for (int j = 0; j < i; ++j) {
				free(tmp_mat[j]);
			}
			free(tmp_mat);
			return NULL;
		}
	}
	return tmp_mat;
}

void read_matrix(int **mat, int *n, int *m)
{
	//read dimensions
	scanf("%d%d", n, m);
	//alloc matrix
	mat = alloc_matrix(*n, *m);
	//read elements of matrix
	for (int i = 0; i < *n; ++i)
		for (int j = 0; j < *m; ++j)
			scanf("%d", &mat[i][j]);
}
