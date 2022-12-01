//Dan Dominic Staicu 311CA
#include "matirx_mem_op.h"

#define MOD 10007

//resize mat keeping only given lines and cols
int **resize_mat(charact *db, int ind)
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
}

void sort_db(charact **db, int index)
{
	//calculate the sum of elements of every mat inside db
	for (int k = 0; k <= index; ++k) {
		(*db)[k].sum = 0;
		for (int i = 0; i < (*db)[k].n; ++i) 
			for (int j = 0; j < (*db)[k].m; ++j) 
				(*db)[k].sum = (*db)[k].sum + (*db)[k].mat[i][j] % MOD;
	}

	//sort the mats inside db according to sum
	for (int i = 0; i < index; ++i)
		for(int j = i + 1; j <= index; ++j)
			if ((*db)[i].sum > (*db)[j].sum) {
				swap_any(&(*db)[i], &(*db)[j], (size_t)sizeof(charact));
			}
}
