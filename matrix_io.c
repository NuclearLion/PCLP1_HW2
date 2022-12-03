//Dan Dominic Staicu 311CA
#include "matrix_io.h"

//alloc memory for a new matrix
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
			free_mat(tmp_mat, i);
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

//print matrix at STDOUT
void display_matrix(int **mat, int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

//alloc memory inside thge database for a new matrix and it's nr of lin & col
void alloc_new_in_db(charact **db, int *mat_cnt, int *index)
{
	++*mat_cnt;
	*index = *mat_cnt - 1;
	*db = realloc(*db, *mat_cnt * sizeof(charact));
	if (!db) {
		fprintf(stderr, "realloc of db failed");
		exit(-1);
	}
}

//free memory of a mat
void free_mat(int **mat, int n)
{
	for (int i = 0; i < n; ++i)
		free(mat[i]);
	free(mat);
}
