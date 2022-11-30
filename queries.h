//Dan Dominic Staicu 311CA
#ifndef _QUERIES_H_
#define _QUERIES_H_

#include "matrix_caracteristics.h"
#include "matrix_io.h"

int check_error(int index, int c_ind);

void interrogate_dim(charact *db, int index);

void query_print(charact *db, int index);

void query_resize(charact *db, int index);

void query_multiply(charact **db, int *index, int *mat_cnt);

#endif
