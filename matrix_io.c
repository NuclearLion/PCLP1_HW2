//Dan Dominic Staicu 311CA
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

void read_matrix(int **mat, int n, int m)
{
	//read elements of matrix from STDIN
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &mat[i][j]);
}

void display_matrix(int **mat, int n, int m)
{
	//print matrix at STDOUT
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void interrogate(caracteristics *db, int index) {
	int ind = 0;
	scanf("%d", &ind);
	if (ind > index) {
		printf("No matrix with the given index\n");
		return;
	}
	printf("%d %d\n", db[ind].n, db[ind].m);
}