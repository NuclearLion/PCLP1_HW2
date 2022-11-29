#include "matirx_mem_op.h"

//resize mat keeping only given lines and cols
int **resize_mat(caracteristics *db, int ind)
{
	int lin = 0, col = 0;
	int *lin_ind, *col_ind;
	read_vect(&lin_ind, &lin);
	read_vect(&col_ind, &col);
	int **new_mat = alloc_matrix(lin, col);
	for (int i = 0; i < lin; ++i) {
		for (int j = 0; j < col; ++j) {
			new_mat[i][j] = db[ind].mat[lin_ind[i]][col_ind[j]];
		}
	}
	db[ind].n = lin;
	db[ind].m = col;
	return new_mat;
	//printf("!!!HERE\n");
	//display_matrix(new_mat, lin, col);
	//printf("%d", db[ind].mat[0][0]);
}
