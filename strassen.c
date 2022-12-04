#include "strassen.h"

//calculate the sum of 2 matrixes and returns the result mat
int **add_mat(int **mat1, int **mat2, int dim)
{
	int **result = alloc_matrix(dim, dim);
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j) {
			result[i][j] = (mat1[i][j] + mat2[i][j]) % MOD;
			result[i][j] = check_pos(result[i][j]);
		}
	return result;
}

//calculate the product mat, using Strassen's recursive algorithm
//by splitting every mat in 4 smaller mats, until every mat has dimension = 1
//not returning the product mat, but passing it as an parameter in order to be
//use less memory by not allocating a new mat every single call of recursivity
//used binary for the names of the smaller mats having in mind where we need to
//add the mid_dimension at mat's indexes
//eg: a[1][0] = mat1[i + mid_dim][j];
void strassen(int **mat1, int **mat2, int dim, int **result)
{
	if (dim == 1) {
		//if mat has dim 1, we have to leave the recurrence and multiply
		result[0][0] = (mat1[0][0] * mat2[0][0]) % MOD;
	} else {
		int mid_dim = dim / 2;

		int **a00 = alloc_matrix(mid_dim, mid_dim);
		int **a01 = alloc_matrix(mid_dim, mid_dim);
		int **a10 = alloc_matrix(mid_dim, mid_dim);
		int **a11 = alloc_matrix(mid_dim, mid_dim);
		int **b00 = alloc_matrix(mid_dim, mid_dim);
		int **b01 = alloc_matrix(mid_dim, mid_dim);
		int **b10 = alloc_matrix(mid_dim, mid_dim);
		int **b11 = alloc_matrix(mid_dim, mid_dim);

		for (int i = 0; i < mid_dim; ++i)
			for (int j = 0; j < mid_dim; ++j) {
				a00[i][j] = mat1[i][j] % MOD;
				a01[i][j] = mat1[i][j + mid_dim] % MOD;
				a10[i][j] = mat1[i + mid_dim][j] % MOD;
				a11[i][j] = mat1[i + mid_dim][j + mid_dim] % MOD;

				b00[i][j] = mat2[i][j] % MOD;
				b01[i][j] = mat2[i][j + mid_dim] % MOD;
				b10[i][j] = mat2[i + mid_dim][j] % MOD;
				b11[i][j] = mat2[i + mid_dim][j + mid_dim] % MOD;
			}
		int **a00b00 = alloc_matrix(mid_dim, mid_dim);
		strassen(a00, b00, mid_dim, a00b00);
		int **a01b10 = alloc_matrix(mid_dim, mid_dim);
		strassen(a01, b10, mid_dim, a01b10);
		int **a00b01 = alloc_matrix(mid_dim, mid_dim);
		strassen(a00, b01, mid_dim, a00b01);
		int **a01b11 = alloc_matrix(mid_dim, mid_dim);
		strassen(a01, b11, mid_dim, a01b11);
		int **a10b00 = alloc_matrix(mid_dim, mid_dim);
		strassen(a10, b00, mid_dim, a10b00);
		int **a11b10 = alloc_matrix(mid_dim, mid_dim);
		strassen(a11, b10, mid_dim, a11b10);
		int **a10b01 = alloc_matrix(mid_dim, mid_dim);
		strassen(a10, b01, mid_dim, a10b01);
		int **a11b11 = alloc_matrix(mid_dim, mid_dim);
		strassen(a11, b11, mid_dim, a11b11);

		//make additons of the smaller mats, according to the alg
		int **res_mat_00 = add_mat(a00b00, a01b10, mid_dim);
		int **res_mat_01 = add_mat(a00b01, a01b11, mid_dim);
		int **res_mat_10 = add_mat(a10b00, a11b10, mid_dim);
		int **res_mat_11 = add_mat(a10b01, a11b11, mid_dim);

		for (int i = 0; i < mid_dim; ++i)
			for (int j = 0; j < mid_dim; ++j) {
				result[i][j] = res_mat_00[i][j] % MOD;
				result[i][j + mid_dim] = res_mat_01[i][j] % MOD;
				result[i + mid_dim][j] = res_mat_10[i][j] % MOD;
				result[i + mid_dim][j + mid_dim] = res_mat_11[i][j] % MOD;
			}

		free_mat(a00b00, mid_dim);
		free_mat(a01b10, mid_dim);
		free_mat(a00b01, mid_dim);
		free_mat(a01b11, mid_dim);
		free_mat(a10b00, mid_dim);
		free_mat(a11b10, mid_dim);
		free_mat(a10b01, mid_dim);
		free_mat(a11b11, mid_dim);
		free_mat(res_mat_00, mid_dim);
		free_mat(res_mat_01, mid_dim);
		free_mat(res_mat_10, mid_dim);
		free_mat(res_mat_11, mid_dim);
		free_mat(a00, mid_dim);
		free_mat(a01, mid_dim);
		free_mat(a10, mid_dim);
		free_mat(a11, mid_dim);
		free_mat(b00, mid_dim);
		free_mat(b01, mid_dim);
		free_mat(b10, mid_dim);
		free_mat(b11, mid_dim);
	}
}
