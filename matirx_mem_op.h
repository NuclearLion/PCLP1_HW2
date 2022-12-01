//Dan Dominic Staicu 311CA
#ifndef _MATRIX_MEM_OP_H_
#define _MATRIX_MEM_OP_H_

#include "queries.h"
#include "utils.h"

int **resize_mat(charact *db, int index);

void sort_db(charact **db, int index);

int **transp_mat(int **mat, int n, int m);

int **mat_pow(int **mat, int dim, int pow);

int **product_mat(int **mat1, int **mat2, int lin1, int l2c1, int col2);

#endif