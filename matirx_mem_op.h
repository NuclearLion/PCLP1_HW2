//Dan Dominic Staicu 311CA
#ifndef _MATRIX_MEM_OP_H_
#define _MATRIX_MEM_OP_H_

#include "queries.h"
#include "utils.h"
#include "matrix_io.h"

#define MOD 10007

int **resize_mat(charact_t *db, int index);

void sort_db(charact_t **db, int index, int cnt_mat);

int **transp_mat(int **mat, int n, int m);

int **product_mat(int **mat1, int **mat2, int lin1, int l2c1, int col2);

int **mat_pow(int **mat, int dim, int pow);

#endif
