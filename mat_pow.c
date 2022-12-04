//Dan Dominic Staicu 311CA
#include "mat_pow.h"

//rise a mat to n pow in logarithmic time
int **mat_pow(int **mat, int dim, int pow)
{
	int **result = alloc_matrix(dim, dim);

	//init result mat as I_n
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j)
			if (i == j)
				result[i][j] = 1;
			else
				result[i][j] = 0;

	while (pow > 0) {
		// if power is odd, we need to multiply the result by mat^3 at that
		//particular step
		if (pow % 2 == 1) {
			int **aux = product_mat(result, mat, dim, dim, dim);
			free_mat(result, dim);
			result = aux;
		}
		//at every step we multiply only by mat^2
		int **aux2 = product_mat(mat, mat, dim, dim, dim);
		free_mat(mat, dim);
		mat = aux2;
		pow /= 2;
	}

	//free the mem of the old matrix
	free_mat(mat, dim);
	return result;
}
