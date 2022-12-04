//Dan Dominic Staicu 311CA
#include "matirx_mem_op.h"

//resize mat keeping only given lines and cols
int **resize_mat(charact *db, int ind)
{
	//read line and col indexes as arrays
	int lin = 0, col = 0;
	int *lin_ind, *col_ind;
	read_vect(&lin_ind, &lin);
	read_vect(&col_ind, &col);

	//create the new smaller mat
	int **new_mat = alloc_matrix(lin, col);
	for (int i = 0; i < lin; ++i)
		for (int j = 0; j < col; ++j)
			new_mat[i][j] = db[ind].mat[lin_ind[i]][col_ind[j]];

	//change dimensions of current mat
	db[ind].n = lin;
	db[ind].m = col;

	//free the arrays
	free(lin_ind);
	free(col_ind);

	return new_mat;
}

//calculate the sum of every mat inside the db and sort them accordingly
void sort_db(charact **db, int index, int cnt_mat)
{
	//if there is no mat, can't sort anything
	if (cnt_mat < 1)
		return;

	//calculate the sum of elements of every mat inside db
	for (int k = 0; k <= index; ++k) {
		(*db)[k].sum = 0;
		for (int i = 0; i < (*db)[k].n; ++i)
			for (int j = 0; j < (*db)[k].m; ++j) {
				(*db)[k].sum = ((*db)[k].sum + (*db)[k].mat[i][j]) % MOD;
				(*db)[k].sum = check_pos((*db)[k].sum);
			}
	}

	//sort the mats inside db according to sum
	for (int i = 0; i < index; ++i)
		for (int j = i + 1; j <= index; ++j)
			if ((*db)[i].sum > (*db)[j].sum)
				swap_any(&(*db)[i], &(*db)[j], (size_t)sizeof(charact));
}

//calculate and return the transposed of any mat
int **transp_mat(int **mat, int n, int m)
{
	int **t_mat = alloc_matrix(m, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			t_mat[j][i] = mat[i][j];
	return t_mat;
}

//return product mat of any 2 mats, regardless their dimensions
//l2c1 means line cnt of mat 2 and col cnt of mat 1, which are the same
//this was checked earlier, inside query_multiply()
int **product_mat(int **mat1, int **mat2, int lin1, int l2c1, int col2)
{
	int **result = alloc_matrix(lin1, col2);

	for (int i = 0; i < lin1; ++i)
		for (int j = 0; j < col2; ++j) {
			//calculate the sum locally and atribute it's vale at the end
			int sum = 0;
			for (int k = 0; k < l2c1; ++k) {
				sum = (sum + mat1[i][k] * mat2[k][j]) % MOD;
				//check if the value is negative, and endit it compliantly
				sum = check_pos(sum);
			}
			result[i][j] = sum;
		}

	return result;
}
