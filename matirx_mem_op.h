//Dan Dominic Staicu 311CA
#ifndef _MATRIX_MEM_OP_H_
#define _MATRIX_MEM_OP_H_

#include "queries.h"
#include "array_op.h"
#include "utils.h"

int **resize_mat(charact *db, int index);

void sort_db(charact **db, int index);

int **transp_mat(int **mat, int n, int m);

#endif