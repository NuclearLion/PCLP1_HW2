//Dan Dominic Staicu 311CA
#ifndef _UTILS_H_
#define _UTILS_H_

#include "matrix_caracteristics.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix_io.h"

#define MOD 10007

void swap_any(void *a, void *b, size_t s);

void read_vect(int **v, int *n);

int check_pos(int sum);

int check_error(int index, int c_ind, int mat_cnt);

void trash(void);

void overwrite(void *a, void *b, size_t s);

#endif
