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

//alloc memory inside thge database for a new matrix and it's nr of lin & col
void alloc_new_in_db(charact **db, int *mat_cnt, int *index) {
	++*mat_cnt;
	*index = *mat_cnt - 1;
	*db = realloc(*db, *mat_cnt * sizeof(charact));
	if (!db) {
		fprintf(stderr, "realloc of db failed");
		exit(-1);
	}
}

//debug function to display everything from matrix
//TO DELETE LATER
void display_db(charact *db, int index) {
	printf("HERE DISPLAY ALL DB: ");
	for (int k = 0; k <= index; ++k) {
		printf("Index %d of N: %d, M: %d, MAT:\n", k, db[k].n, db[k].m);
		for (int i = 0; i < db[k].n; ++i) {
			for (int j = 0; j < db[k].m; ++j)
				printf("%d ", db[k].mat[i][j]);
			printf("\n");
		}
	}
}