//Dan Dominic Staicu 311CA
#ifndef _MATRIX_IO_H_
#define _MATRIX_IO_H_

#include <stdio.h>
#include <stdlib.h>
#include "matrix_caracteristics.h"

int **alloc_matrix(int n, int m);

void read_matrix(int **mat, int n, int m);

void display_matrix(int **mat, int n, int m);

void interrogate(caracteristics *db, int index);

#endif