#include "strassen.h"

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

int **strassen(int **mat1, int **mat2, int dim)
{
	int **result = alloc_matrix(dim, dim);

	if (dim == 1) {
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
		
		int **res_mat_00 = add_mat(strassen(a00, b00, mid_dim), 
					strassen(a01, b10, mid_dim), mid_dim);
		int **res_mat_01 = add_mat(strassen(a00, b01, mid_dim),
					strassen(a01, b11, mid_dim), mid_dim);
		int **res_mat_10 = add_mat(strassen(a10, b00, mid_dim),
					strassen(a11, b10, mid_dim), mid_dim);
		int **res_mat_11 = add_mat(strassen(a10, b01, mid_dim),
					strassen(a11, b11, mid_dim), mid_dim);

		for (int i = 0; i < mid_dim; ++i)
			for (int j = 0; j < mid_dim; ++j) {
				result[i][j] = res_mat_00[i][j] % MOD;
				result[i][j + mid_dim] = res_mat_01[i][j] % MOD;
				result[i + mid_dim][j] = res_mat_10[i][j] % MOD;
				result[i + mid_dim][j + mid_dim] = res_mat_11[i][j] % MOD;
			}

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
	return result;
}
