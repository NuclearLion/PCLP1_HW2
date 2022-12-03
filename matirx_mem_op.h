//Dan Dominic Staicu 311CA
#ifndef _MATRIX_MEM_OP_H_
#define _MATRIX_MEM_OP_H_

#include "queries.h"
#include "utils.h"

#define MOD 10007

int **resize_mat(charact *db, int index);

void sort_db(charact **db, int index, int cnt_mat);

int **transp_mat(int **mat, int n, int m);

int **product_mat(int **mat1, int **mat2, int lin1, int l2c1, int col2);

#endif