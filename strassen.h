#ifndef _STRASSEN_H_
#define _STRASSEN_H_

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "matrix_io.h"

#define MOD 10007

int **add_mat(int **mat1, int **mat2, int dim);

//int **strassen(int **mat1, int **mat2, int dim);

void strassen(int **mat1, int **mat2, int dim, int **result);

#endif