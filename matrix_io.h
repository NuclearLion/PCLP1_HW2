//Dan Dominic Staicu 311CA
#ifndef _MATRIX_IO_H_
#define _MATRIX_IO_H_

#include <stdio.h>
#include <stdlib.h>

#include "matrix_caracteristics.h"
#include "queries2.h"

int **alloc_matrix(int n, int m);

void read_matrix(int **mat, int n, int m);

void display_matrix(int **mat, int n, int m);

void interrogate(charact *db, int index);

void alloc_new_in_db(charact **db, int *mat_cnt, int *index);

void display_db(charact *db, int index);

void free_mat(int **mat, int n);

#endif
